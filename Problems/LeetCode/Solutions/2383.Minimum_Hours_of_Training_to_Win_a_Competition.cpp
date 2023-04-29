class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int exp = experience[n-1]+1;
        for( int i = n-2 ; i >= 0 ; i-- )
            exp = max(exp-experience[i],experience[i]+1);
        int ene = energy[n-1]+1;
        for( int i = n-2 ; i >= 0 ; i-- )
            ene += energy[i];
        return max(exp-initialExperience,0) + max(ene-initialEnergy,0);
    }
};
