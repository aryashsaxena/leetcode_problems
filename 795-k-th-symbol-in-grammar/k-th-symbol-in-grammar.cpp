class Solution {
public:
    int f(int n,int k,int root){
        if(n==1) return root;

        int tot=1<<(n-1);
        
        if(k<=(tot/2)){
            int nxt=root==0 ? 0 : 1; 
            return f(n-1,k,nxt);
        }
        else{
            int nxt=root==0? 1 : 0;
            return f(n-1,k-(tot/2),nxt);
        }
    }

    int kthGrammar(int n, int k) {
        return f(n,k,0);
    }
};