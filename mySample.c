#include <stdio.h>

int buyAndSellManage(int *stockPrice,int day);

int main(void){
    int stockPrice[100] = { 0 };
    int day = 1;
    int i = 0;
    int gain = 0;

    //入力
    while(stockPrice[day - 1] != -1){
        printf("%d日目の株価? ",day);
        scanf("%d",&stockPrice[day]);
        day++;
        i++;
    }

    //株価表示
    printf("\nStock Price:\n");
    for(i = 1;i < day-1;i++){
        printf("Day %d: %d\n",i,stockPrice[i]);
    }
    printf("\n");

    //結果表示
    gain = buyAndSellManage(stockPrice,day);
    printf("Total Earning = %d\n",gain);

    return 0;
}
int buyAndSellManage(int *stockPrice,int day){
    int myStock = 0;
    int myProfit = 0;
    int i = 1;
    int nowaday = 1;
    int max = 0;
    for(i = 1;i < day-1;i++){
        //買う
        if(myStock == 0){
            //しかし最終日は買わない、絶対に買わせない。
            if(i + 1 < day-2){
                if(stockPrice[i] < stockPrice[i + 1]){
                    myStock = stockPrice[i];
                    printf("buy : day %d at %d\n",i,stockPrice[i]);
                }else{
                    myStock = stockPrice[i + 1];
                    printf("buy : day %d at %d\n",(i + 1),stockPrice[i + 1]);
                }
            }
        }else{
            //売る
            //最大値を求める
            for(nowaday = i;nowaday < day-1;nowaday++){
                if(max < stockPrice[nowaday]){
                    max = stockPrice[nowaday];
                }
            }
            //一番高く売れるのが近い日を探す
            for(nowaday = i;nowaday < day-1;nowaday++){
                if(max == stockPrice[nowaday]){
                    myProfit += stockPrice[nowaday] - myStock;
                    printf("sell : day %d at %d\n",nowaday,stockPrice[nowaday]);
                    i = nowaday;//最大値の次の日から購入させる
                    break;
                }
            }
            myStock = 0;//持株をなくす
        }          
    }
    return myProfit;
}

