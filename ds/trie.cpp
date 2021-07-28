/// Name: Trie
/// Description: Kickstart Round A Final Ques
/// Detail: Insert and Query Support
/// Guarantee: struct FU {
typedef struct data{
	data* bit[26];
	int cnt = 0;
}trie;
trie* head;
void insert(string &s){
	trie* cur = head;
	for(auto &it:s){
		int b = it - 'A';
		if(!cur->bit[b])
			cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}
int query(trie* cur, int lvl){
	if(!cur)
		return 0;
	int ans = (cur -> cnt / k);
	for(int i = 0; i <= 25; i++)
		if(cur -> bit[i])
			ans += query(cur -> bit[i], lvl + 1);
	return ans;
}