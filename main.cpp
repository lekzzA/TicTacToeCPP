#include<bits/stdc++.h>

using namespace std;

class Player{
    private:
        string name;
        char symbol;
    public:
        Player(){
            this->name = " ";
            this->symbol = ' ';
        }
        bool setSymbol(char a){
            this->symbol = a;
            return true;
        }
        bool setName(string a){
            this->name = a;
            return true;
        }
        string getName(){
            return this->name;
        }
        char getSymbol(){
            return this->symbol;
        }
};

class Canvas{
    private:
        char board[3][3];
    public:
        Canvas(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    board[i][j] = ' ';
                }
            }
        }

        bool isFull(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[i][j] == ' ')
                        return false;
                }
            }
            return true;
        }
        void displayBoard(){
            for(int i = 0; i < 3; i++){
                cout<<" | ";
                for(int j = 0; j < 3; j++){
                    cout<<board[i][j]<<" | ";
                }
                cout<<"\n";
            }
        }

        void clearBoard(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    board[i][j] = ' ';
                }
            }
        }

        bool isValidMove(int r, int c){
            if(r < 3 && c < 3 && board[r][c] == ' ')
                return true;
            return false;
        }

        bool updateBoard(int r, int c, char symbol){
            if(board[r][c] == ' '){
                board[r][c] = symbol;
                return true;
            }
            else{
                cout<<"\nWrong Move. That tile is already played. Please select other tile!!!";
                return false;
            }
        }

        char getSymbol(int r, int c){
            return board[r][c];
        }

};

class TicTacToe{
    private:
        Player players[2];
        Canvas canvas;
    public:
        TicTacToe(){
            for(int i = 0; i < 2; i++){
                players[i] = Player();
            }
            canvas = Canvas();
        }

        bool Won(Player p){
            char s1, s2, s3;

            for(int i = 0;  i < 3; i++){
                
                s1 = canvas.getSymbol(i, 0);
                s2 = canvas.getSymbol(i, 1);
                s3 = canvas.getSymbol(i, 2);

                if(s1 == p.getSymbol() && s2 == p.getSymbol() && s3 == p.getSymbol())
                    return true;
                
                s1 = canvas.getSymbol(0, i);
                s2 = canvas.getSymbol(1, i);
                s3 = canvas.getSymbol(2, i);

                if(s1 == p.getSymbol() && s2 == p.getSymbol() && s3 == p.getSymbol())
                    return true;
            }
            bool f = true;
            for(int i = 0; i < 3; i++){
                if(p.getSymbol() != canvas.getSymbol(i, i)){
                    f = false;
                    break;
                }
            }
            if(f)
                return true;
            for(int i = 0; i < 3; i++){
                if(p.getSymbol() != canvas.getSymbol(i, 3-i)){
                    f = false;
                    break;
                }
            }
            if(f)
                return true;
            return false;
        }

        void play(){
            string s;
            char ch;
            int r, c, i = 0;
            for(int i = 0; i < 2; i++){
                ch = ' ';
                cout<<"\nEnter name of Player "<<i+1<<" : ";
                // cin.ignore();
                getline(cin>>ws, s);
                // cin.ignore();
                while(ch != 'x' && ch != 'X' && ch != 'o' && ch!= 'O'){
                cout<<"\nChoose Symbol(X/O) for "<<s<<" : ";
                cin>>ch;
                if(ch != 'x' && ch != 'X' && ch != 'o' && ch!= 'O'){
                    cout<<"\n Please Enter only 'X' or 'O'";
                }
                }
                players[i].setName(s);
                players[i].setSymbol(ch);
            }
            canvas.clearBoard();
            canvas.displayBoard();
            i = 0;
            while(!canvas.isFull()){
                do{
                cout<<"\n"<<players[i].getName()<<" Enter the row for move: ";
                cin>>r;
                cout<<"\n"<<players[i].getName()<<" Enter the column for move: ";
                cin>>c;
                } while(!canvas.isValidMove(r, c));

                canvas.updateBoard(r, c, players[i].getSymbol());
                canvas.displayBoard();
                if(Won(players[i])){
                    cout<<"\n"<<players[i].getName()<<" won the game !!!!! ";
                    break;
                }

                i = i == 0?1:0;
                if(canvas.isFull()){
                    cout<<"\nThis is a TIE!!!";
                    break;
                }
            }
        }
};


int main(){
    TicTacToe t;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        t.play();
        cout<<"\n\n\n\t\tWant to play again? ";
        cin>>ch;
    }
    return 0;
}