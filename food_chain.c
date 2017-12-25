//
// Created by Jim on 2017/12/25.
//
#include <stdio.h>
#include <stdlib.h>

int *set, *value;
int n, k, x, y, d, cnt;
int fa(int id) { //查找id所属类别，带路径压缩
    if (id!=set[id]) {
        int tmp=set[id];
        set[id]=fa(set[id]);
        value[id]=(value[id]+value[tmp])%3;
    }
    return set[id];
}

int main(void) {
    int i;
    scanf("%d %d", &n, &k);
    set = (int *)malloc(sizeof(int) * (n+1));
    value = (int *)malloc(sizeof(int) * (n+1));
    for(i=1; i<=n; i++){
        set[i]=i;
    } //初始化并查集
    for(i=0; i<k; i++) {
        scanf("%d %d %d",&d, &x, &y);
        if(x>n || y>n) {
            cnt++;
            continue;
        }
        if(d==1) {   //说法：1  x  y      x和y同类？
            if(fa(x)==fa(y)){
                if(value[x]!=value[y]) {
                    cnt++;
                }
            }  // x和y同集合
            else {  // x和y不同集合
                value[set[x]]=(value[y]-value[x]+3)%3;
                set[set[x]]=set[y]; //将x所在集并入y所在集
            }
        }
        else {  //说法：2  x  y    x 吃 y？
            if(x==y) {
                cnt++;
                continue;
            }
            if(fa(x)==fa(y)){
                if(value[x] != (value[y]+1)%3) {
                    cnt++;
                }
            } // x和y同集合
            else {  // x和y不同集合
                value[set[x]]=(value[y]-value[x]+4)%3;
                set[set[x]]=set[y]; //将x所在集并入y所在集
            }
        }
    } //for
    printf("%i\n", cnt);
    return 0;
} //end

