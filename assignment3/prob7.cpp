#include <iostream>
#include <vector>

using namespace std;

int countStoneToCapture(int x,int y,int color,vector<vector<int> > &matrix,int &count_down,int&count_up,int&count_right,int&count_left,int &count_left_down,int &count_right_down,int &count_left_up,int &count_right_up){
    //down
    int y_1=y;
    int x_1=x;
    count_down=0;
    while(y<7){
        if (matrix[y+1][x]!=color && matrix[y+1][x]!=0 ){
            if (y+1==7){
                count_down = 0;
                break;
            }
            count_down++;
            y++;
            continue;
        }
        if (matrix[y+1][x]==color)
            break;
        if (matrix[y+1][x]==0){
            count_down = 0;
            break;
        }
    }
    x=x_1;
    y=y_1;
    //left_down
    count_left_down=0;
    while(y<7 && x>0){
        if (matrix[y+1][x-1]!=color && matrix[y+1][x-1]!=0){
            if (y+1==7){
                count_left_down = 0;
                break;
            }
            if (x-1==0){
                count_left_down=0;
                break;
            }
            count_left_down++;
            x=x-1;
            y++;
            continue;
        }
        if (matrix[y+1][x-1]==color)
            break;
        if (matrix[y+1][x-1]==0){
            count_left_down=0;
            break;
        }
    }
    x=x_1;
    y=y_1;
    //right_down
    count_right_down=0;
    while(y<7 && x<7){
        if (matrix[y+1][x+1]!=color && matrix[y+1][x+1]!=0){
            if (y+1==7){
                count_right_down = 0;
                break;
            }
            if (x+1==7){
                count_right_down=0;
                break;
            }
            count_right_down++;
            x++;
            y++;
            continue;
        }
        if (matrix[y+1][x+1]==color)
            break;
        if (matrix[y+1][x+1]==0){
            count_right_down=0;
            break;
        }
    }
    x=x_1;
    y=y_1;
    //up
    count_up=0;
    while (y>0){
        if (matrix[y-1][x]!=color && matrix[y-1][x]!=0 ){
            if (y-1==0){
                count_up = 0;
                break;
            }
            count_up++;
            y=y-1;
            continue;
        }
        if (matrix[y-1][x]==color)
            break;
        if (matrix[y-1][x]==0){
            count_up = 0;
            break;
        }
    }
    x=x_1;
    y=y_1;
    //left_up
    count_left_up=0;
    while(y>0&&x>0){
        if (matrix[y-1][x-1]!=color && matrix[y-1][x-1]!=0){
            if (y-1==0){
                count_left_up = 0;
                break;
            }
            if (x-1==0){
                count_left_up=0;
                break;
            }

            count_left_up++;
            y=y-1;
            x=x-1;
            continue;
        }
        if (matrix[y-1][x-1]==color)
            break;
        if (matrix[y-1][x-1]==0){
            count_left_up=0;
            break;
        }
    }
    x=x_1;
    y=y_1;
    //right_up
    count_right_up=0;
    while(y>0&&x<7){
        if(matrix[y-1][x+1]!=color && matrix[y-1][x+1]!=0){
            if (y-1==0){
                count_right_up = 0;
                break;
            }
            if (x+1==7){
                count_right_up=0;
                break;
            }

            count_right_up++;
            y=y-1;
            x++;
            continue;
        }
        if (matrix[y-1][x+1]==color)
            break;
        if (matrix[y-1][x+1]==0){
            count_right_up=0;
            break;
        }
    }
    x=x_1;
    y=y_1;
    //right
    count_right=0;
    while(x<7){
        if(matrix[y][x+1]!=color && matrix[y][x+1]!=0){
            if (x+1==7){
                count_right=0;
                break;
            }
            count_right++;
            x++;
            continue;
        }
        if (matrix[y][x+1]==color)
            break;
        if (matrix[y][x+1]==0){
            count_right=0;
            break;
        }
    }
    x=x_1;
    y=y_1;
    //left
    count_left=0;
    while(x>0){
        if(matrix[y][x-1]!=color && matrix[y][x-1]!=0){
            if (x-1==0){
                count_left= 0;
                break;
            }
            count_left++;
            x=x-1;
            continue;
        }
        if (matrix[y][x-1]==color)
            break;
        if (matrix[y][x-1]==0){
            count_left=0;
            break;
        }
    }
    if (count_down==0 && count_up==0 &&count_right==0&&count_left==0 &&count_left_down==0 &&count_right_down==0&&count_left_up==0&&count_right_up==0)
        return 0;
    else return 1;
}
void change_stone(int x,int y,int color,vector<vector<int> > &matrix,int &count_down,int&count_up,int&count_right,int&count_left,int &count_left_down,int &count_right_down,int &count_left_up,int &count_right_up){
    //down
    int y_1=y;
    int x_1=x;
    if (count_down!=0){
        matrix[y][x]=color;
        while(y<7){
            if (matrix[y+1][x]!=color && matrix[y+1][x]!=0 ){
                matrix[y+1][x]=color;
                y++;
                continue;
            }
            if (matrix[y+1][x]==color)
                break;
        }
    }
    x=x_1;
    y=y_1;
    //left_down
    if (count_left_down!=0){
        matrix[y][x]=color;
        while(y<7 && x>0){
            if (matrix[y+1][x-1]!=color && matrix[y+1][x-1]!=0){
                matrix[y+1][x-1]=color;
                x=x-1;
                y++;
                continue;
            }
            if (matrix[y+1][x-1]==color)
                break;
        }
    }
    x=x_1;
    y=y_1;
    //right_down
    if (count_right_down!=0){
        matrix[y][x]=color;
        while(y<7 && x<7){
            if (matrix[y+1][x+1]!=color && matrix[y+1][x+1]!=0){
                matrix[y+1][x+1]=color;
                x++;
                y++;
                continue;
            }
            if (matrix[y+1][x+1]==color)
                break;
        }
    }
    x=x_1;
    y=y_1;
    //up
    if (count_up!=0){
        matrix[y][x]=color;
        while (y>0){
            if (matrix[y-1][x]!=color && matrix[y-1][x]!=0 ){
                matrix[y-1][x]=color;
                y=y-1;
                continue;
            }
            if (matrix[y-1][x]==color)
                break;
        }
    }
    x=x_1;
    y=y_1;
    //left_up
    if (count_left_up!=0){
        matrix[y][x]=color;
        while(y>0&&x>0){
            if (matrix[y-1][x-1]!=color && matrix[y-1][x-1]!=0){
                matrix[y-1][x-1]=color;
                y=y-1;
                x=x-1;
                continue;
            }
            if (matrix[y-1][x-1]==color)
                break;
        }
    }
    x=x_1;
    y=y_1;
    //right_up
    if (count_right_up!=0){
        matrix[y][x]=color;
        while(y>0&&x<7){
            if(matrix[y-1][x+1]!=color && matrix[y-1][x+1]!=0){
                matrix[y-1][x+1]=color;
                y=y-1;
                x++;
                continue;
            }
            if (matrix[y-1][x+1]==color)
                break;
        }
    }
    x=x_1;
    y=y_1;
    //right
    if (count_right!=0){
        matrix[y][x]=color;
        while(x<7){
            if(matrix[y][x+1]!=color && matrix[y][x+1]!=0){
                matrix[y][x+1]=color;
                x++;
                continue;
            }
            if (matrix[y][x+1]==color)
                break;
        }
    }
    x=x_1;
    y=y_1;
    //left
    if (count_left!=0){
        matrix[y][x]=color;
        while(x>0){
            if(matrix[y][x-1]!=color && matrix[y][x-1]!=0){
                matrix[y][x-1]=color;
                x=x-1;
                continue;
            }
            if (matrix[y][x-1]==color)
                break;
        }
    }
}
int computerspick(vector<vector<int> > matrix,int &c_x,int &c_y,int &c_count){
    int count_down,count_up,count_right,count_left;
    int count_left_down,count_right_down,count_left_up,count_right_up;
    c_count=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if (matrix[i][j]==0){
                countStoneToCapture(j,i,2,matrix,count_down,count_up,count_right,count_left,count_left_down,count_right_down,count_left_up,count_right_up);
                if(count_down>c_count){
                    c_x=j;
                    c_y=i;
                    c_count=count_down;
                }
                if(count_up>c_count){
                    c_x=j;
                    c_y=i;
                    c_count=count_up;
                }
                if(count_right>c_count){
                    c_x=j;
                    c_y=i;
                    c_count=count_right;
                }
                if(count_left>c_count){
                    c_x=j;
                    c_y=i;
                    c_count=count_left;
                }
                if(count_left_down>c_count){
                    c_x=j;
                    c_y=i;
                    c_count=count_left_down;
                }
                if(count_right_down>c_count){
                    c_x=j;
                    c_y=i;
                    c_count=count_right_down;
                }
                if(count_left_up>c_count){
                    c_x=j;
                    c_y=i;
                    c_count=count_left_up;
                }
                if(count_down>c_count){
                    c_x=j;
                    c_y=i;
                    c_count=count_right_up;
                }
            }
    if (c_count==0)
        return 0;
    else return 1;
}

int main()
{
    vector<vector<int> > matrix(8, vector<int>(8, 0));
    int count_down,count_up,count_right,count_left;
    int count_left_down,count_right_down,count_left_up,count_right_up;
    int c_count,c_x,c_y;
    matrix[4][3]=2;
    matrix[3][4]=2;
    matrix[3][3]=1;
    matrix[4][4]=1;
    while (true)
    {
        cout << "   0 1 2 3 4 5 6 7" << endl;
        cout << "  -----------------" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << i << "|";
            for (int j = 0; j < 8; j++)
            {
                cout << " " << matrix[i][j];
            }
            cout <<" |"<< endl;
        }
        cout << "  -----------------" << endl;
        cout << "your turn : ";
        int x,y;
        cin>>x>>y;
        
        int temp1=countStoneToCapture(x,y,1,matrix,count_down,count_up,count_right,count_left,count_left_down,count_right_down,count_left_up,count_right_up);
        change_stone(x,y,1,matrix,count_down,count_up,count_right,count_left,count_left_down,count_right_down,count_left_up,count_right_up);
        cout << "   0 1 2 3 4 5 6 7" << endl;
        cout << "  -----------------" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << i << "|";
            for (int j = 0; j < 8; j++)
            {
                cout << " " << matrix[i][j];
            }
            cout <<" |"<< endl;
        }
        cout << "  -----------------" << endl;
        cout<<"computer turn"<<endl;
        int temp3=computerspick(matrix,c_x,c_y,c_count);
        int count_1=0;
        int count_2=0;
        if (temp1==0&& temp3 ==0){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(matrix[i][j]==1)
                        count_1++;
                    if(matrix[i][j]==2)
                        count_2++;
                }
            }
            if (count_1>count_2)
                cout<<"user win!!";
            if (count_1==count_2)
                cout<<"Draw!!";
            if (count_1<count_2)
                cout<<"computer win!!";
            break;
        }
        if(temp3==0)
            continue;
        int temp2=countStoneToCapture(c_x,c_y,2,matrix,count_down,count_up,count_right,count_left,count_left_down,count_right_down,count_left_up,count_right_up);
        change_stone(c_x,c_y,2,matrix,count_down,count_up,count_right,count_left,count_left_down,count_right_down,count_left_up,count_right_up);
        
    }
}
