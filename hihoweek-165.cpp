#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, result;
    cin >> s;
    long int count[26] = {0};
    long int i;
    for(i=0; i<s.length(); i++){
        count[s[i] - 'a'] ++;
    }

    int start = 0;
    while(true){
        // 找到第一个不等于0的字母
        int i = start;
        while(i < 26 && count[i] == 0){
            i ++;
        }
        if(i >= 26){
            cout << result << endl;
            break ;
        }
        
        start = i;
        count[start] --;
        result += ('a' + start);
        bool flag = false;
        int j = start + 1;
        while(j < 26 && count[j]  == 0){
            j ++;
        }
        if(j >= 26){
            if(count[start] == 0 && ('a' + start != result[result.length() - 1])){
                cout << result << endl;
                break;
            }else{
                cout << "INVALID" << endl;
                break;
            }
        }else{
            result += ('a' + j);
            count[j] --;
        }
    }
    return 0;
}