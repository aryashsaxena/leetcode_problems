class Solution {
public:
bool isvovel(char &ch)
{
    if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U' )
    return true;
    return false;
}
    bool halvesAreAlike(string s) {
        
        int n=s.size();
        int x=0;
        for(int i=0;i<n/2;i++)
        {
            if(isvovel(s[i]))
            x++;
        }

        int y=0;
        for(int i=n/2;i<n;i++)
        {
            if(isvovel(s[i]))
            y++;
        }
        return x==y;

    }
};