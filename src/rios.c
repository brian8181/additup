#include "RIMS.h"
/*
   Copyright (c) 2013 Frank Vahid, Tony Givargis, and
   Bailey Miller. Univ. of California, Riverside and Irvine.
   RIOS version 1.2
*/
typedef struct task {
   unsigned long period;      // Rate at which the task should tick
   unsigned long elapsedTime; // Time since task's last tick
   int state;                 //Current state
   int (*TickFct)(int);       // Function to call for task's tick
} task;

enum TG_States { TG_None, TG_s1 };
int TickFct_Toggle(int);

enum SQ_States { SQ_None, SQ_s1, SQ_s2, SQ_s3 };
int TickFct_Sequence(int);

unsigned char TimerFlag = 0;
void TimerISR(void) {
   if (TimerFlag) {
      printf("Timer ticked before task processing done.\n");
}
   else {
      TimerFlag = 1;
   }
   return;
}

int main(void) {
   task tasks[2];
   const unsigned char tasksNum = 2;
   const unsigned long tasksPeriodGCD = 200; // Timer tick rate
   const unsigned long periodToggle   = 1000;
   const unsigned long periodSequence = 200;

   unsigned char i = 0;
   tasks[i].period      = periodToggle;
   tasks[i].elapsedTime = tasks[i].period;
   tasks[i].TickFct     = &TickFct_Toggle;
   tasks[i].state       = TG_None;
   i++ ;
   tasks[i].period      = periodSequence;
   tasks[i].elapsedTime = tasks[i].period;
   tasks[i].TickFct     = &TickFct_Sequence;
   tasks[i].state       = SQ_None;

   TimerSet(tasksPeriodGCD);
   TimerOn();

   while(1) {
      // Heart of the scheduler code
      for (i = 0; i < tasksNum; ++i) {
         if (tasks[i].elapsedTime >= tasks[i].period) { // Ready
            tasks[i].state = tasks[i].TickFct(tasks[i].state);
            tasks[i].elapsedTime = 0;
         }
         tasks[i].elapsedTime += tasksPeriodGCD;
      }
      TimerFlag = 0;
      while (!TimerFlag) {
         Sleep();
      }
   }
   return 0;
}

int TickFct_Toggle(int state) {
   switch(state) { // Transitions
      case TG_None: // Initial transition
         B0 = 0; // Initialization behavior
         state = TG_s1;
         break;
      case TG_s1:
         state = TG_s1;
         break;
      default:
         state = TG_None;
    }
    switch(state) { // State actions
      case TG_s1:
         B0 = !B0;
         break;
      default:
         break;
   }
   return state;
}
int TickFct_Sequence(int state) {
   switch(state) { // Transitions
      case SQ_None: // Initial transition
         state = SQ_s1;
         break;
      case SQ_s1:
         state = SQ_s2;
         break;
      case SQ_s2:
         state = SQ_s3;
         break;
      case SQ_s3:
         state = SQ_s1;
         break;
      default:
         state = SQ_None;
    }
    switch(state) { // State actions
      case SQ_s1:
         B2 = 1;
         B3 = 0;
         B4 = 0;
         break;
      case SQ_s2:
         B2 = 0;
         B3 = 1;
         B4 = 0;
         break;
      case SQ_s3:
         B2 = 0;
         B3 = 0;
         B4 = 1;
         break;
      default:
         break;
   }
   return state;
}