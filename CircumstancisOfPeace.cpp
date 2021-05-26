
//#include <iostream>
//#include <fstream>

//using namespace std;
#include <iostream>
#include <fstream>

using namespace std;


#define MYFILE "input.txt"
#define SKIP '.'
#define LOCX 'x'
#define EMPTY '_'

inline int fline(char* line, int size_n) {
    for (int i = 0; i < size_n; i++) {
        if (line[i] == LOCX) { return i; }
    }
    return -1;
}

inline int fshaft(char** matrix, int n_i, int size_m) {
    int j = 0;
    for (j = 0; j < size_m; j++) {
        if (matrix[j][n_i] == LOCX) { return j; }
    }
    return -1;
}
 
inline int fbishop(char** matrix, int m_j, int n_i, int size_m, int size_n) {
    int ok = m_j > n_i;
    int j = (m_j - n_i) * ok;
    int i = (n_i - m_j) * (1 - ok);

    for (j; j < size_m and i < size_n;) {
        if (matrix[j][i] == LOCX) { return j; }
        j++; i++;
    }

    ok = (m_j + n_i) < size_m;
    j = (size_m-1) * (1 - ok) + (m_j + n_i) * ok;
    i = n_i * (1 - ok);

    for (j; j >= 0 and i < size_n;) {
        if (matrix[j][i] == LOCX) { return j; }
        j--; i++;
    }

    return -1;
}

bool fcheckstar(char** matrix, int m_j, int n_i, int size_m, int size_n) {
    /*if (fline(matrix[m_j], size_n) >= 0) { return true; }*/
    if (fshaft(matrix, n_i, size_m) >= 0) { return true; }
    if (fbishop(matrix, m_j, n_i, size_m, size_n) >= 0) { return true; }
    return false;
}

int main(){
    //1 start the initialization
    fstream input;
    input.open(MYFILE, ios::in);
    if (!input) {
        return 1;
    }

    int n; input >> n;
    int m; input >> m;
    char** data = new char* [m];
    for (int j = 0; j < m; j++) {
        data[j] = new char[n];
    }
    //1.1   fill data field
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (!input.eof()) {
                input >> data[j][i];
                continue;
            }
            break;
        }
    }
    input.close();


    //2 initial run
    for (int j = 0; j < m; j++) {
        if (j < 0) { return 1; }

        int i = fline(data[j], n);
        if (i < 0) { i = 0; }
        else { data[j][i] = EMPTY; i++; }

        for (i; i < n; i++) {
            if (data[j][i] == SKIP) { continue; }
            if (!fcheckstar(data, j, i, m, n)) {
                data[j][i] = LOCX;
                break;
            }
        }

        if (fline(data[j], n) < 0) { j -= 2; }
    }


    //3 end up the algorithm
    fstream output;
    output.open("output.txt", ios::out);
    if (!output) {
        return 1;
    }
    else {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                output << data[j][i];
            }
            output << "\n";
        }
        output.close();
    }
    
    for (int j = 0; j < m; j++) {
        delete[] data[j];
    }
    delete[] data;
    
    return 0;
}
