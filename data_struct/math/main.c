#include "head.h"
int main()
{
    link_list_t A = CreateEpLinkList();
    link_list_t B = CreateEpLinkList();
    link_list_t C = CreateEpLinkList();
    InserttypedataoPostLinkList(A, 0, 1);
    InserttypedataoPostLinkList(A, 1, 3);
    InserttypedataoPostLinkList(A, 2, 5);
    InserttypedataoPostLinkList(A, 3, 7);
    InserttypedataoPostLinkList(A, 4, 9);
    InserttypedataoPostLinkList(A, 5, 10);
    InserttypedataoPostLinkList(B, 0, 2);
    InserttypedataoPostLinkList(B, 1, 4);
    InserttypedataoPostLinkList(B, 2, 5);
    InserttypedataoPostLinkList(B, 3, 8);
    InserttypedataoPostLinkList(B, 4, 11);
    InserttypedataoPostLinkList(B, 5, 15);
    SortList(A, B, C);
    ShowLinkList(C);
    ClearLinkList(A);
    ClearLinkList(B);
    ClearLinkList(C);
    free(A);
    free(B);
    free(C);
    return 0;
}