class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if((purchaseAmount%10)<5){
            return 100-(purchaseAmount-(purchaseAmount%10));
        }
        return  100-(purchaseAmount+(10-purchaseAmount%10));
    }
};