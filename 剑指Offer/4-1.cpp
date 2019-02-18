int move(char str[]) {
	int backspace = 0;
	for(int i = 0 ; i<strlen(str) ; i++){
		if(str[i] == " ") backspace++;
	}
	int move = backspace*2 ;
	for(int i = strlen(str)-1 ; i>=0 ;i-- ){
		if(str[i] != " ") str[i+move] = str[i];
		else if(str[i] == " ") 
	}
}
