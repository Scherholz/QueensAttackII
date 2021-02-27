#include "../include/stdc++.h"

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int ret=0;
    if(n==0)return 0;
    
    //up
    int boundUp[2] = {n+1,c_q};
    cout<< "bound up : " << boundUp[0] << "," << boundUp[1] << endl;
    //down
    int boundDown[2] = {0,c_q};
    cout<< "bound down : " << boundDown[0] << "," << boundDown[1] << endl;
    //left
    int boundLeft[2] = {r_q,0};
    cout<< "bound left : " << boundLeft[0] << "," << boundLeft[1] << endl;
    //right
    int boundRight[2] = {r_q,n+1};
    cout<< "bound right : " << boundRight[0] << "," << boundRight[1] << endl;  
    //UR
    int boundURaux = c_q+(n+1-r_q) <= n+1 ? c_q+(n+1-r_q) : n+1;
    int boundUR[2] = {r_q+(boundURaux-c_q), boundURaux};
    cout<< "bound UR : " << boundUR[0] << "," << boundUR[1] << endl;
    //UL
    int boundULaux = c_q-(n+1-r_q) >= 0 ? c_q-(n+1-r_q) : 0;
    int boundUL[2] = {r_q+(c_q-boundULaux),boundULaux};
    cout<< "bound UL : " << boundUL[0] << "," << boundUL[1] << endl;  
    //DR
    int boundDRaux = c_q+(r_q) <= n+1 ? c_q+(r_q) : n+1;
    int DRaux2 = (boundDRaux-c_q);
    int boundDR[2] = {r_q-DRaux2,boundDRaux};
    cout<< "bound DR : " << boundDR[0] << "," << boundDR[1] << endl; 
    //DL
    int boundDLaux = c_q-(r_q) >= 0 ? c_q-(r_q) : 0;
    int DLaux2 = (c_q-boundDLaux);
    int boundDL[2] = {r_q-DLaux2,boundDLaux};
    cout<< "bound DL : " << boundDL[0] << "," << boundDL[1] << endl;
    
    
    for(auto v:obstacles){
        
        int r_o = v[0];
        int c_o = v[1];
        //Grab new bound up
        if(r_o<boundUp[0] && r_o>r_q && c_o==c_q){
            boundUp[0]=r_o;
            cout<< "new bound up : " << boundUp[0] << "," << boundUp[1] << endl;
        }
        //Grab new bound down
        if(r_o>boundDown[0] && r_o<r_q && c_o==c_q){
            boundDown[0]=r_o;
            cout<< "new bound down : " << boundDown[0] << "," << boundDown[1] << endl;
        }
        //Grab new bound left
        if(c_o>boundLeft[1] && c_o<c_q && r_o==r_q){
            boundLeft[1]=c_o;
            cout<< "new bound left : " << boundLeft[0] << "," << boundLeft[1] << endl;
        }
        //Grab new bound right
        if(c_o<boundRight[1] && c_o>c_q && r_o==r_q){
            boundRight[1]=c_o;
            cout<< "new bound right : " << boundRight[0] << "," << boundRight[1] << endl;
        }
        //Grab new bound UR
        if(r_o>r_q && c_o > c_q && r_o<boundUR[0] && c_o<boundUR[1]){
            if(r_o-r_q==c_o-c_q){
                boundUR[0]=r_o;
                boundUR[1]=c_o;
                cout<< "new bound UR : " << boundUR[0] << "," << boundUR[1] << endl;
            }
        }
        //Grab new bound UL
        if(r_o>r_q && c_o < c_q && r_o<boundUL[0] && c_o>boundUL[1]){
            if(r_o-r_q==c_q-c_o){
                boundUL[0]=r_o;
                boundUL[1]=c_o;
                cout<< "new bound UL : " << boundUL[0] << "," << boundUL[1] << endl;
            }
        }
        //Grab new bound DR
        if(r_o<r_q && c_o > c_q && r_o>boundDR[0] && c_o<boundDR[1]){
            if(r_q-r_o==c_o-c_q){
                boundDR[0]=r_o;
                boundDR[1]=c_o;
                cout<< "new bound DR : " << boundDR[0] << "," << boundDR[1] << endl;
            }
        }
        //Grab new bound DL
        if(r_o<r_q && r_o>boundDL[0] && c_o<c_q && c_o>boundDL[1]){
            if(r_q-r_o==c_q-c_o){
                boundDL[0]=r_o;
                boundDL[1]=c_o;
                cout<< "new bound DL : " << boundDL[0] << "," << boundDL[1] << endl; 
            }
        }
    }
    
    //add dist to boundUp to ret
    ret+= boundUp[0]-r_q-1;
    cout << "RET up +=" << boundUp[0]-r_q-1 <<endl;
    //add dist to boundDown to ret
    ret+= r_q-boundDown[0]-1;
    cout << "RET down +=" << r_q-boundDown[0]-1<<endl;
    //add dist to boundLeft to ret
    ret+= c_q-boundLeft[1]-1;
    cout << "RET left +=" << c_q-boundLeft[1]-1<<endl;
    //add dist to boundRight to ret
    ret+= boundRight[1]-c_q-1;
    cout << "RET right +=" << boundRight[1]-c_q-1<<endl;
    //add dist to boundUR to ret
    ret+= boundUR[0]-r_q-1;
    cout << "RET UR +=" << boundUR[0]-r_q-1<<endl;
    //add dist to boundUL to ret
    ret+= boundUL[0]-r_q-1;
    cout << "RET UL +=" << boundUL[0]-r_q-1<<endl;
    //add dist to boundDR to ret
    ret+= r_q-boundDR[0]-1;
    cout << "RET DR +=" << r_q-boundDR[0]-1<<endl;
    //add dist to boundDL to ret
    ret+= (r_q-boundDL[0]-1);
    cout << "RET DL +=" << r_q-boundDL[0]-1<<endl;

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
