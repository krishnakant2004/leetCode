class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int skill_size = skill.size();
        int mana_size = mana.size();

        // vector<long long> prefixSum(sn,0);
        long long sum = 0;
        for(int i = 0;i<skill_size;i++){
            sum += skill[i];
            // prefixSum[i] = sum;
        }

        long long comp_time = 0;

        for(int i = 0;i<mana_size;i++){
            int currStTime = comp_time;
            comp_time += mana[i] * sum;

            //modify time for successor potions
            if(i == mana.size()-1) break;
            
            long long wizComTime = comp_time;
            long long getT = comp_time;
            for(int k = skill.size()-1;k>0;k--){
                wizComTime = wizComTime - skill[k]*mana[i];
                getT = getT - skill[k-1]*mana[i+1];

                if(getT < wizComTime){
                    getT = wizComTime;
                }
                // if(getT <= currStTime){
                //     getT = currStTime;
                //     break;
                // }
            }
            comp_time = getT;
        }
        return comp_time;
    }

    
};