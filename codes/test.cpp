using namespace std;
#include <bits/stdc++.h>
int tictactoe(int curr_state[]){
    /*check for win*/
    if(curr_state[0]==2 && curr_state[1] ==2 && curr_state[2]==0)
        return 2;
    if(curr_state[0]==2 && curr_state[1] ==0 && curr_state[2]==2)
        return 1;
    if(curr_state[0]==0 && curr_state[1] ==2 && curr_state[2]==2)
        return 0;
    if(curr_state[0]==2 && curr_state[3] ==2 && curr_state[6]==0)
        return 6;
    if(curr_state[0]==2 && curr_state[6] ==2 && curr_state[3]==0)
        return 3;
    if(curr_state[6]==2 && curr_state[3] ==2 && curr_state[0]==0)
        return 0;
    if(curr_state[3]==2 && curr_state[4] ==2 && curr_state[5]==0)
        return 5;
    if(curr_state[3]==2 && curr_state[4] ==0 && curr_state[5]==2)
        return 4;
    if(curr_state[3]==0 && curr_state[4] ==2 && curr_state[5]==2)
        return 3;
    if(curr_state[1]==2 && curr_state[4] ==2 && curr_state[7]==0)
        return 7;
    if(curr_state[1]==2 && curr_state[4] ==0 && curr_state[7]==2)
        return 4;
    if(curr_state[1]==0 && curr_state[4] ==2 && curr_state[7]==2)
        return 1;
    if(curr_state[6]==2 && curr_state[7] ==2 && curr_state[8]==0)
        return 8;
    if(curr_state[6]==2 && curr_state[7] ==0 && curr_state[8]==2)
        return 7;
    if(curr_state[6]==0 && curr_state[7] ==2 && curr_state[8]==2)
        return 6;
    if(curr_state[2]==2 && curr_state[5] ==2 && curr_state[8]==0)
        return 8;
    if(curr_state[2]==2 && curr_state[5] ==0 && curr_state[8]==2)
        return 5;
    if(curr_state[2]==0 && curr_state[5] ==2 && curr_state[8]==2)
        return 2;
    if(curr_state[0]==2 && curr_state[4] ==2 && curr_state[8]==0)
        return 8;
    if(curr_state[0]==2 && curr_state[4] ==0 && curr_state[8]==2)
        return 4;
    if(curr_state[0]==0 && curr_state[4] ==2 && curr_state[8]==2)
        return 0;
    if(curr_state[2]==2 && curr_state[4] ==2 && curr_state[6]==0)
        return 6;
    if(curr_state[2]==2 && curr_state[4] ==0 && curr_state[6]==2)
        return 4;
    if(curr_state[2]==0 && curr_state[4] ==2 && curr_state[6]==2)
        return 2;
    /*winning over*/
    int sum=0,i;
    for(i=0;i<9;++i)
        sum+=curr_state[i];
    if(sum==1 && curr_state[4]==1)
        return 0;
    else if(sum==1 && curr_state[4]==0)
        return 4;
    if(curr_state[4]==2)
    {
        if(curr_state[0]==1 && curr_state[1]==1 && curr_state[2]==0)
            return 2;
        if(curr_state[0]==1 && curr_state[1]==0 && curr_state[2]==1)
            return 1;
        if(curr_state[0]==0 && curr_state[1]==1 && curr_state[2]==1)
            return 0;
        if(curr_state[6]==1 && curr_state[7]==1 && curr_state[8]==0)
            return 8;
        if(curr_state[6]==1 && curr_state[7]==0 && curr_state[8]==1)
            return 7;
        if(curr_state[6]==0 && curr_state[7]==1 && curr_state[8]==1)
            return 6;
        if(curr_state[0]==1 && curr_state[3]==1 && curr_state[6]==0)
            return 6;
        if(curr_state[0]==1 && curr_state[3]==0 && curr_state[6]==1)
            return 3;
        if(curr_state[0]==0 && curr_state[3]==1 && curr_state[6]==1)
            return 0;
        if(curr_state[2]==1 && curr_state[5]==1 && curr_state[8]==0)
            return 8;
        if(curr_state[2]==1 && curr_state[5]==0 && curr_state[8]==1)
            return 5;
        if(curr_state[2]==0 && curr_state[5]==1 && curr_state[8]==1)
            return 2;
        if(((curr_state[0]==1 && curr_state[8]==1) || (curr_state[2]==1 && curr_state[6]==1)) && curr_state[1]==0)
            return 1;
        if(((curr_state[0]==1 && curr_state[8]==1) || (curr_state[2]==1 && curr_state[6]==1)) && curr_state[3]==0)
            return 3;
        if(((curr_state[0]==1 && curr_state[8]==1) || (curr_state[2]==1 && curr_state[6]==1)) && curr_state[7]==0)
            return 7;
        if(((curr_state[0]==1 && curr_state[8]==1) || (curr_state[2]==1 && curr_state[6]==1)) && curr_state[5]==0)
            return 5;
    }
    if(curr_state[4]==1)
    {
        if(curr_state[1]==1 && curr_state[7]==0)
            return 7;
        if(curr_state[2]==1 && curr_state[6]==0)
            return 6;
        if(curr_state[5]==1 && curr_state[3]==0)
            return 3;
        if(curr_state[7]==1 && curr_state[1]==0)
            return 1;
        if(curr_state[6]==1 && curr_state[2]==0)
            return 2;
        if(curr_state[3]==1 && curr_state[5]==0)
            return 5;
        if(curr_state[8]==1)
        {
            if(curr_state[2]==0)
                return 2;
            else if(curr_state[6]==0)
                return 6;
        }
    }
    if(curr_state[0]==0)
        return 0;
    if(curr_state[2]==0)
        return 2;
    if(curr_state[6]==0)
        return 6;
    if(curr_state[8]==0)
        return 8;
    for(i=0;i<9;++i)
    {
        if(curr_state[i]==0)
            return i;
    }
}

int main(int argc, char **argv){
	int n;
	int curr_state[10] = {0};
	for(int i = 1; i < 10; i++)
		curr_state[i - 1] = argv[i][0] - '0';

	cout<<tictactoe(curr_state);
}