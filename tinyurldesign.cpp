#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
// You can type code here and execute it.
class TinyURLService{
    private:
        long COUNTER = 1;
        string s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string base = "http://www.tinyurl.com/";
        map<long, string> lmap;
        map<long, string> smap;
    public:
        string encodeURL(string longURL){
            string r = base62(COUNTER);
            lmap[COUNTER] = longURL;
            smap[COUNTER] = r;
            COUNTER++;
            return  base + r;
        }
    
        string decodeURL(string shortURL){
            long c = base10(shortURL.substr(base.size()));
            return lmap[c];
        }
    
        long base10(string e){
            long n = 0;
            for(char c : e){
                if(c >= '0' && c <= '9'){
                    n = n * 62 + c - '0'; 
                }else if(c >= 'a' && c <= 'z'){
                    n = n * 62 + 10 + (c - 'a');
                }else{
                    n = n * 62 + 36 + (c - 'A');
                }
            }
            
            return n;
        }
    
        string base62(long n){
            string r;
            while(n){
                r.insert(0, 1, s[n % 62]);
                n /= 62;
            }
            
            while(r.size() < 6){
                r.insert(0, 1, '0');
            }
            
            return r;
        }
    
};

int main() {
    string in = "https://leetcode.com/problems/design-tinyurl";
    TinyURLService tiny;
    cout << tiny.decodeURL(tiny.encodeURL(in)) << endl;

    return 0;
}