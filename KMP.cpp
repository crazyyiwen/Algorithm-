void getNext(string T, int *next){
	int i = 1;
	int j = 0;
	next[i] = 0;

	while(i < T[0]){
		if((0 == j) && (T[i] == T[j])){
			i++;
			j++;
			if(T[i] != T[j]){
				next[i] = j;
			}
			else{
				next[i] = next[j];
			}
		}
		else{
			j == next[j];
		}
	}
}
//return the position of T after the posth of S
//if the position does not exist return 0
int indexKMP(string S, string T, int pos){
	int i = 0;
	int j = 1;
	int next[255];

	getNext(T, next);
	
	while((i <=S[0]) && (j <= T[0])){
		if(S[i] == T[i]){
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}
}
