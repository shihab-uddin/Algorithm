#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > itemInfo(1000);

int index = 1;
int weight, price, knapsack, totalPrice;
double unitPrice;
priority_queue<pair<double, int> > pq;

int main(){

    ifstream input("items.txt");
    if(!input.is_open()){
        cout<<"File not found"<<endl;
    }else{
        input>>knapsack;
        while(input>>weight>>price){
            itemInfo[index++] = make_pair(weight, price);
        }
    }

    for(int i = 1; i < index; i++){
        cout<<"Item : "<<i<<" Weight : "<<itemInfo[i].first<<" Price : $"<<itemInfo[i].second<<endl;
    }

    for(int i = 1; i < index; i++){ // Calculation unit price of all products
        unitPrice = (float)(itemInfo[i].second/itemInfo[i].first);
        pq.push(make_pair(unitPrice, i));
    }

    while(!pq.empty() && knapsack != 0){ // Taking items one by one according to highest unit profit & Also checking knapsack is full or not.
        pair<int, int> frnt = pq.top(); // Taking a item which has highest unit profit.
        pq.pop();
        if(itemInfo[frnt.second].first <= knapsack){ // if item's weight less than size of knapsack then take it.
            totalPrice += itemInfo[frnt.second].second;
            cout<<"Selected Item : "<<frnt.second<<" Weight : "<<itemInfo[frnt.second].first<<" Price : "<<itemInfo[frnt.second].second<<endl;
            knapsack -= itemInfo[frnt.second].first;
        }else{
            totalPrice = knapsack*frnt.first;
            cout<<"Selected Item : "<<frnt.second<<" Weight : "<<itemInfo[frnt.second].first<<" Price : "<<itemInfo[frnt.second].second<<" Fraction : "<<knapsack<<"/"<<itemInfo[frnt.second].first<<endl;
            break;
        }
    }

    return 0;
}


/*Input :

10  ------->Knapsack Size.
4 12 ------>Weight, Price.
8 32
2 40
6 30
1 50

*/
