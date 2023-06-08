// chaliye shuru krte hai
// co-written by AJTITAN & Aniruddh Joshi
#include <bits/stdc++.h>
using namespace std;
void display(vector<vector<char>> board)
{
    // cout<<"PLAYER - 1 [X]t PLAYER - 2 [O]nn";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " \n";
    cout << "\t\t     |     |     \n";
}
bool check_the_name(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == ' '))
        {
            return false;
        }
    }
    return true;
}
bool check_player(string s, string name1, string name2)
{
    return s == name1 || s == name2;
}
bool check_the_space(int n, vector<vector<char>> arr)
{
    if (n > 2 || n < 0)
        return false;
    return true;
}
bool check_the_place(int r, int c, vector<vector<char>> arr)
{
    if (arr[r][c] != '*')
        return false;
    return true;
}
bool check_win(vector<vector<char>> board)
{
    bool xwin = 0, owin = 0;
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') || board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
        {
            return true;
        }
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') || board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            return true;
        }
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
        return true;
    if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
        return true;
    return false;
}
int main()
{
    while (1)
    {
        vector<vector<char>> arr{
            {'*', '*', '*'},
            {'*', '*', '*'},
            {'*', '*', '*'}};
        display(arr);
        cout<<endl;
        pair<string, char> name1;
        pair<string, char> name2;
        name1.second = 'X';
        name2.second = 'O';
        cout << "enter the player name for X : ";
        cin >> name1.first;
        while (!check_the_name(name1.first))
        {
            cout << "enter the valid player name for X : ";
            cin >> name1.first;
        }
        cout << "enter the player name for O : ";
        cin >> name2.first;
        while (!check_the_name(name2.first))
        {
            cout << "enter the valid player name for O : ";
            cin >> name2.first;
        }
        cout << "who plays first," << name1.first << " or " << name2.first << " : " << endl;
        string temp;
        pair<string, char> t1;
        pair<string, char> ans;

        pair<string, char> t2;
        cin >> temp;
        while (!check_player(temp, name1.first, name2.first))
        {
            cout << temp << " is not a registered name.";
            cout << "who plays first," << name1.first << " or " << name2.first << " : " << endl;
            cin >> temp;
        }

        if (temp == name2.first)
        {
            t2.first = name1.first;
            t2.second = name1.second;
            t1.first = name2.first;
            t1.second = name2.second;
        }
        else
        {
            t2.first = name2.first;
            t2.second = name2.second;
            t1.first = name1.first;
            t1.second = name1.second;
        }
        bool f = 1;
        // cout << "test" << endl;
        for (int i = 0; i < 9; i++)
        {
            pair<string, char> curr;
            if (f)
                curr = t1;
            else
                curr = t2;
            cout<<endl<<"player of current turn = "<<curr.first<<endl;
            int row, coloumn, c = 0;
            while (c == 0)
            {
                cout << "enter the row from 0 to 2 : " << endl;
                cin >> row;
                while (!check_the_space(row, arr))
                {
                    cout << "enter the row from 0 to 2 : " << endl;
                    cin >> row;
                }
                cout << "enter the coloumn from 0 to 2 : " << endl;
                cin >> coloumn;
                while (!check_the_space(coloumn, arr))
                {
                    cout << "enter the coloumn from 0 to 2 : " << endl;
                    cin >> coloumn;
                }
                if (check_the_place(row, coloumn, arr))
                    c = 1;
            }
            arr[row][coloumn] = curr.second;
            f = !f;
            cout << endl;
            display(arr);
            cout << endl;
            if (check_win(arr))
            {
                ans = curr;
                break;
            }
        }
        if (ans.first == name1.first || ans.first == name2.first)
            cout << ans.first << " wins the match\n";
        else
            cout << "match ends with draw\n";
        cout << "do you want to play again(yes/no)";
        string s;
        cin >> s;
        for(int i=0;i<10000;i++){
            if(s=="yes" || s=="no") break;
            cin>>s;
        }
        if (s == "no")
        {
            cout << "Bye";
            break;
        }
    }

    return 0;
}
