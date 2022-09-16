#include <iostream>
using namespace std;

class TicTacToe{
private:
    int board[3][3];
public:
    TicTacToe();
    ~TicTacToe();
    void displayBoard();
    void Play();
    bool Win();
    void P1();
    void P2();
    static int turns;


};

int TicTacToe::turns=1;

TicTacToe::TicTacToe(){
    for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                board[i][j]=0;
        }
    }
    cout<<"******NEW GAME******"<<"\n\n";
}
TicTacToe::~TicTacToe(){cout<<"******GAME ENDED******";}

void TicTacToe::displayBoard(){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (j<2){
            cout<<board[i][j]<<"  |  ";}
            else{cout<<board[i][j];}
        }
        if (i<2){
        cout<<endl<<"--------------"<<endl;}
        else{cout<<endl;}
    }
}

void TicTacToe::P1(){
    cout<<"Player 1 turn!!"<<endl;
    int r,c;
    cout<<"Enter row :";cin>>r;
    cout<<"Enter column :";cin>>c;
    if (board[r-1][c-1]==2){
        cout<<"Space already occupied,enter again!!"<<endl;
        while(board[r][c]==2){
        cout<<"Enter row again :";cin>>r;
        cout<<"Enter column again:";cin>>c;
        }
    }else{
        board[r-1][c-1]=1;
    }

}

void TicTacToe::P2(){
    cout<<"Player 2 turn!!"<<endl;
    int r,c;
    cout<<"Enter row :";cin>>r;
    cout<<"Enter column :";cin>>c;
    if (board[r-1][c-1]==1){
        cout<<"Space already occupied,enter again!!"<<endl;
        while(board[r-1][c-1]==1){
        cout<<"Enter row again :";cin>>r;
        cout<<"Enter column again:";cin>>c;
        board[r-1][c-1]=2;
        }
    }else{
        board[r-1][c-1]=2;
    }

}

bool TicTacToe::Win(){
    if (
        board[0][0]==1&&board[0][1]==1&&board[0][2]==1||
        board[1][0]==1&&board[1][1]==1&&board[1][2]==1||
        board[2][0]==1&&board[2][1]==1&&board[2][2]==1||
        board[0][0]==1&&board[1][0]==1&&board[2][0]==1||
        board[0][1]==1&&board[1][1]==1&&board[2][1]==1||
        board[0][2]==1&&board[1][2]==1&&board[2][2]==1||
        board[0][0]==1&&board[1][1]==1&&board[2][2]==1||
        board[0][2]==1&&board[1][1]==1&&board[2][0]==1
    ){cout<<"PLAYER 1 won!!"<<endl;return true;}
    else if(
        board[0][0]==2&&board[0][1]==2&&board[0][2]==2||
        board[1][0]==2&&board[1][1]==2&&board[1][2]==2||
        board[2][0]==2&&board[2][1]==2&&board[2][2]==2||
        board[0][0]==2&&board[1][0]==2&&board[2][0]==2||
        board[0][1]==2&&board[1][1]==2&&board[2][1]==2||
        board[0][2]==2&&board[1][2]==2&&board[2][2]==2||
        board[0][0]==2&&board[1][1]==2&&board[2][2]==2||
        board[0][2]==2&&board[1][1]==2&&board[2][0]==2
    ){cout<<"PLAYER 2 won!!"<<endl;return true;}
    else{return false;}


}

void TicTacToe::Play(){
    while (turns<=9 && Win()==false){
        P1();
        turns++;
        displayBoard();
        if(Win()==true){break;};
        P2();
        displayBoard();
        turns++;
    }
    if (turns>9){cout<<"Game Drawn!!!"<<endl;}
}

int main(){
    TicTacToe game;
    game.displayBoard();//only to show empty board first time
    game.Play();
    return 0;
}
