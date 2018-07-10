void _InOrder(BiTree T){
    _InitStack(S);
    BiTree p = T;
    while(p||isempty(s)){
        if(p){
            s.push(p);
            p=p->left;
        }
        else {
            s.pop(p);
            visit(p);
            p=p->right;
        }
    }
}