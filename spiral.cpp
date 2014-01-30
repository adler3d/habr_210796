#include <stdio.h>
#include <string>
#include <vector>
using std::vector;using std::string;
struct t_habr_2014_01_30{
  struct vec2i{int x;int y;void operator+=(const vec2i&v){x+=v.x;y+=v.y;};};
  static bool check(const vector<int>&arr,int n,const vec2i&pos,const vec2i&dv){
    auto e=pos;e+=dv;
    if(e.x>=n)return false;
    if(e.x<+0)return false;
    if(e.y>=n)return false;
    if(e.y<+0)return false;
    return !arr[e.x+e.y*n];
  }
  static vec2i turn(const vec2i&v){vec2i tmp={-v.y,+v.x};return tmp;}
  static string IToS(const int&val){char c[40];sprintf(c,"%02i",val);return string(c);}
  static string main(int n){
    vector<int> arr(n*n);
    vec2i pos={0,0}; vec2i dv={1,0};
    for(int id=1;id<=n*n;id++){
      arr[pos.x+pos.y*n]=id;
      if(!check(arr,n,pos,dv))dv=turn(dv);
      pos+=dv;
    }
    string out;
    for(int y=0;y<n;y++){for(int x=0;x<n;x++){out+=IToS(arr[x+y*n])+" ";}out+="\n";}
    return out;
  }
};
int main(){printf("%s\n",t_habr_2014_01_30::main(9).c_str());return 0;}
