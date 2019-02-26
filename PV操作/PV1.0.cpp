reader_preference{
	int reader_count = 0;
	sema rmutex = 1 ;
	sema mutex = 1 ;
	reader(){
		rmutex.p();
		if(!reader_count){
			mutex.p();
		}
		reader_count++
		rmutex.v();
		
		reading progress
		
		rmutex.p()
		reader_count--;
		if(!reader_count){
			mutex.v();
		}
		rmutex.v()
	} 
	writer(){
		mutex.p()
		writing_progress 
		mutex.v()
	}
}

writer_preference{
	int writer_count = 0;
	int reader_count = 0;
	sema wmutex = 1;
	sema rmutex = 1;
	sema mutex = 1;
	sema readable = 1;
	writer(){
		wmutex.p();
		if(!writer_count){
			readable.p();
		}
		writer_count++;
		wmutex.v();
		
		mutex.p()
		writing progress;
		mutex.v()
		
		wmutex.p();
		writer_count--;
		if(!writer_count){
			readable.v();
		}
		wmutex.v();
	}
	reader(){
		readable.p();
		rmutex.p()
		if(!reader_count){
			mutex.p();
		}
		reader_count++;
		rmutex.v()
		readable.v()
		
		reading progress
		
		rmutex.p()
		reader_count--;
		if(!reader_count){
			mutex.v();
		}
		rmutex.v()
	}
}

no_preference{
	sema mutex = 1;
	sema wmutex = 1 ;
	sema rmutex = 1 ;
	sema queue = 1;
	int reader_count = 0;
	int writer_count = 0;
	reader() {
		queue.p();
		rmutex.p();
		if(!read_count){
			mutex.p();
		}
		reader_count++;
		rmutex.v();
		queue.v();
		
		reading progess
		
		rmutex.p();
		read_count--;
		if(!read_count){
			mutex.v();
		}
		rmutex.v();
	} 
	writer(){
		queue.p();
		mutex.p();
		queue.v();
		
		writing progess 
		mutex.v();
	}
}

