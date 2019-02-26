sema c[5] = {1,1,1,1,1};
sema plate = 3;


void philosopher(int i){
	if(i % 2==0){
		take(c[i%5]);
		take(c[(i+1)%5]);
//		eat();
		p(plate);
		//如果是N个盘子的情况，到底应该是怎么呢？因为盘子是没有自己的序号的
		//所以肯定不需要使用chop的数组进行描述 
		v(plate);
		put(c[i%5]);
		put(c[(i+1)%5]);
	}
	else{
		take(c[(i+1)%5]);
		take(c[i%5]);
//		eat();
		p(plate);
		v(plate);
		put(c[(i+1)%5]);
		put(c[i%5]);
		
	}
}

 
