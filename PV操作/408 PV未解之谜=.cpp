sema c[5] = {1,1,1,1,1};
sema plate = 3;


void philosopher(int i){
	if(i % 2==0){
		take(c[i%5]);
		take(c[(i+1)%5]);
//		eat();
		p(plate);
		//�����N�����ӵ����������Ӧ������ô�أ���Ϊ������û���Լ�����ŵ�
		//���Կ϶�����Ҫʹ��chop������������� 
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

 
