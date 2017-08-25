#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;
    string s;
    int result = 0;
    
    while(T--){
        cin >> s;
        result = 0;
        int total = s.length();
        int num0 = 0;
        int i;
        for(i=0; i<total; i++){
            if(s[i] == '0')
                num0 ++;
        }
        
        int min = total + 1;
        // 在左边和右边分别需要调整的个数
        int left = 0;
        int right = num0;
        if(left + right < min){
            min = left + right;
        }
        // 第i个（包括i）之前都是0，第i个之后都是1
        for(i=0; i<total; i++){
            if(s[i] == '0'){
                right --;
            }else{
                left ++;
            }
            if(left + right < min){
                min = left + right;
            }
        }
        
        cout << min << endl;
    }
    return 0;
}
