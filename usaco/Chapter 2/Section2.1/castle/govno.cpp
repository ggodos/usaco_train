#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

string obj0[] {
"####",
"#  #",
"####"
};


const char walls[] {'D', 'R', 'U', 'L'};

void gotoxy(int column, int row)
{
	HANDLE hCons;
	COORD crd;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);	  
	crd.X = (short)column;
	crd.Y = (short)row;
	SetConsoleCursorPosition(hCons, crd);
}


vector<char> getNotWalls(int number) {
    vector<char> temp;
    bool w[4] = { false };
    if (number == 0) {
        return temp;
    }
    while (number != 0) {
        if (number >= 8) {
            w[0] = true;
            number -= 8;
        }
        if (number >= 4) {
            w[1] = true;
            number -= 4;
        }
        if (number >= 2) {
            w[2] = true; 
            number -= 2;
        }
        if (number == 1) {
            w[3] = true;
            number--;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!w[i])
            temp.push_back(walls[i]);
    }
    return temp;
}
int main() {
    //ios::sync_with_stdio(0);
    ifstream fin("castle.in");
    ofstream fout("test.txt");
    int M = 0, N = 0;
    fin >> M >> N;
    // vector<vector<string>> v(N*M);
    // for (auto& i : v) {
    //     int t;
    //     fin >> t;
    //     i = getNotWalls(t);
    // }
    // int counter = 0;
    // for (auto& i : v) {
    //     for (auto& j : i) {
    //         cout << j << " ";
    //     }
    //     if (counter == 7) {
    //         cout << "\n";
    //         counter = 0;
    //     }
    //     cout << "\n";
    // }


    char field[N + N - 1][M + M - 1];
    for (int i = 0; i < N + N - 1; ++i) {
        for (int j = 0; j < M + M - 1; ++j) {
            field[i][j] = '#';
        }
    }

    for (int i = 0; i < N + N - 1; i+=2) {
        for (int j = 0; j < M + M - 1; j+=2) {
            field[i][j] = ' ';
            int f; fin >> f;
            auto sp = getNotWalls(f);
            for (auto& k : sp) {
                switch (k) {
                    case 'D':
                        field[i+1][j] = ' ';
                        break;
                    case 'R':
                        field[i][j+1] = ' ';
                        break;
                    case 'U':
                        field[i-1][j] = ' ';
                        break;
                    case 'L':
                        field[i][j-1] = ' ';
                        break;
                }
            }
        }
    }
    for (int i = 0; i <= M+M; i++)
        cout << "# ";
    cout << "\n";
    for (auto& i : field) {
        cout << "# ";
        for (auto& j : i) {
            cout << j << ' ';
        }
        cout << "#";
        cout << '\n';
    }
    for (int i = 0; i <= M+M; i++)
        cout << "# ";
    cout << "\n";
    // system("cls");
    // gotoxy(0, 0);
    // cout << obj0[0];
    // gotoxy(0, 1);
    // cout << obj0[1];
    // gotoxy(0, 2);
    // cout << obj0[2];
    // gotoxy(5, 0);
    // cout << obj0[3];
    // gotoxy(5, 1);
    // cout << obj0[4];
    // gotoxy(5, 2);
    // cout << obj0[5];
    // gotoxy(5, 3);
    return 0;
}






// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
// #       #       #       #       #       #       #           #
// # # # # #   #   #   #   #   #   #   #   #   #   # # #   #   #
// #           #       #       #       #       #       #       #
// #   # # # # # # # # # # # # # # # # # # # # # # #   #   #   #
// #   #   #                               #       #   #       #
// # # #   # # # # # # # # # # # # # # # # # # #   #   #   #   #
// #       #                                   #   #   #       #
// # # #   #   # # # # # # # # # # # # # # #   #   # # #   #   #
// #   #   #   #   #                   #   #   #   #   #       #
// #   # # #   #   # # # # #   # # # # #   #   # # #   # # # # #
// #       #   #           #   #           #       #           #
// #   # # #   #   # # # # #   # # # # #   # # #   #   # # #   #
// #   #   #   #   #                   #   #       #           #
// # # #   #   #   #   # # # # # # #   #   #   # # # # # # # # #
// #       #   #   #   #           #   #   #-->#               #
// # # #   #   # # #   #   # # #   #   # # #   #   # # # # #   #
// #   #   #           #           #           #   #           #
// #   # # #   # # #   #   # # #   #   # # #   #   #   # # # # #
// #       #   #   #   #           #   #   #   #   #           #
// #   # # #   #   #   # # # # # # #   #   #   #   # # # # #   #
// #   #   #   #   #                   #   #   #   #           #
// # # #   # # #   # # # # #   # # # # # # # # #   #   # # # # #
// #   #   #   #           #   #       #       #   #           #
// #   #   # # # # # # # # #   # # # # # # # # #   # # # # #   #
// #   #   #   #   #                   #   #       #           #
// #   # # #   #   # # # # # # # # # # #   #   # # #   # # # # #
// #   #   #   #   #           #           #                   #
// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// 1   0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  
// 2   15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  
// 3   30  31  32  33  34  35  36  37  38  39  40  41  42  43  44
// 4   45  46  47  48  49  50  51  52  53  54  55  56  57  58  59  
// 5   60  61  62  63  64  65  66  67  68  69  70  71  72  73  74
// 6   75  76  77  78  79  80  81  82  83  84  85  86  87  88  89  
// 7   90  91  92  93  94  95  96  97  98  99  100 101 102 103 104
// 8   105 106 107 108 109 110 111 112 113 114 115 116 117 118 119
// 9   120 121 122 123 124 125 126 127 128 129 130 131 132 133 134
// 10  135 136 137 138 139 140 141 142 143 144 145 146 147 148 149
// 11  150 151 152 153 154 155 156 157 158 159 160 161 162 163 164
// 12  165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 
// 13  180 181 182 183 184 185 186 187 188 189 190 191 192 193 194
// 14  195 196 197 198 199 200 201 202 203 204 205 206 207 208 209

