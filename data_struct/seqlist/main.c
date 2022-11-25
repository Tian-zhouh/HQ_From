#include"head.h"
int main(){
    seqlist_t *p=CreateEpSeqlist();
    seqlist_t *q=CreateEpSeqlist();
    int a[]={1,3,5,7};
    int b[]={5,7,9,11};
    int i=0;
    for(;i<sizeof(a)/sizeof(int);i++){
        InsertIntoSeqlist(p,i,a[i]);
    }
    for(i=0;i<sizeof(b)/sizeof(int);i++){
        InsertIntoSeqlist(q,i,b[i]);
    }
    Or(p,q);
    ShowSeqlist(q);
    free(p);
    free(q);
    return 0;
}