{
	int reader_count = 0 ;
	//int writer_count = 0 ;
	sema rmutex = 1;
	//sema wmutex = 1;
	sema mutex = 1;
	sema queue = 1;
	
	reader(){
		queue.p();
		rmuetex.p();
		if(readercount != 0){
			mutex.p();
		}
		readercount++;
		rmutex.v();
		queue.v(); 
		
		reader_progress;
		
		rmuetex.p();
		readercount--;
		if(readercount != 0){
			mutex.v();
		}	
		rmutex.v();
	}
	writer(){
		queue.p();
		mutex.p();
		queue.v();
		
		writing progress;
		
		mutex.v();
	}
} 


int reader_count = 0 ;
int writer_count = 0 ;
sema rmutex = 1;
sema wmutex = 1;
sema mutex = 1;
sema readable = 1;
{
	writer(){
		wmutex.p();
		if(!writer_count){
			readable.p();
		}
		writer_count++;
		wmutex.v();
		
		mutex.p();
		writing_progress;
		mutex.v();
		
		wmutex.p();
		writer_count--;
		if(!writer_count) {
			readable.v();
		}
		wmutex.v();
	}
	reader(){
		readable.p();
		rmutex.p();
		readcount++;
		if(!readcount){
			mutex.p()
		}
		rmutex.v();
		readable.v();
		
		reading progress
		
		rmutex.p();
		if(!readcount){
			mutex.v();
		}
		readcount--;
		rmutex.v();
	}
}

