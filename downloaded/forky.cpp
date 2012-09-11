#include<iostream>
using namespace std;
int main() {
int i=1;
fork();
fork();
cout<<"process : "<<getpid()<<"\t"<<"parent : "<<getppid()<<"\n";
sleep(2);
return 0;
}
