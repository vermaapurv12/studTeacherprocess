#include<stdio.h>
#include<stdbool.h>
struct process{
  bool pen;
  bool paper;
  bool questionPaper;
  bool status;
}procStudent[3];

struct availResc{
  bool pen;
  bool paper;
  bool questionPaper;
}a;

bool assignment(int i){

  if(procStudent[i].pen && a.paper && a.questionPaper){
  procStudent[i].status=true;
  return true;
  }

  if(a.pen && procStudent[i].paper && a.questionPaper){
    procStudent[i].status=true;
    return true;
  }

  if(a.pen && a.paper && procStudent[i].questionPaper){
    procStudent[i].status=true;
    return true;
  }
  return false;
}

void allocateResc(int i){


  if(i==0)
  {
    a.paper=true;
    a.questionPaper=true;
  }
  else if(i==1)
  {
    a.questionPaper=true;
    a.pen=true;
  }
  else if(i==2){

    a.pen=true;
    a.paper=true;
  }

}

void deallocate(){
  a.pen=false;
  a.paper=false;
  a.questionPaper=false;
}

int main(){
  int ch;
  bool r;
  procStudent[0].pen=true;
  procStudent[1].paper=true;
  procStudent[2].questionPaper=true;
  for(int i=0;i<3;i++){
    procStudent[i].status=false;
  }
  printf("--------------------------Process Scheduler---------------------\n");
  printf("Student process 1 has Pen\n");
  printf("Student process 2 has Paper\n");
  printf("Student process 3 has Question Paper\n");
  printf("\n");
  printf("Press 0 for allocating pen and paper\n");
  printf("Press 1 for allocating paper and question paper\n");
  printf("Press 2 for allocating question paper and pen\n");
  printf("\n");

  for(int i=0;i<3;i++){
    printf("Enter choice\n");
  scanf("%d",&ch);
  if(ch!=0&&ch!=1&&ch!=2){
    printf("invalid choice\n");
    i--;
  }
  allocateResc(ch);
  for(int j=0;j<3;j++){
    if(procStudent[j].status!=true){
      if(r=assignment(j)){
        printf("Process %d exited\n",j+1);
      }
    }
  }
  deallocate();
  }
}
