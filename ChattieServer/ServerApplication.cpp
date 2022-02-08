#include "ServerApplication.h"

		ServerApplication::ServerApplication(){
							
			////
		//	requestManager = new RequestManager();
			
			serverCore = new ServerCore();
			netCore = new NetCore(serverCore);
			
			/////
		//	run();	
			
			
					
		}
		
		void ServerApplication::run(){
		
		//	serverCore->run();	
		
		}
		
		
		
		
		////////////
		
		ServerApplication::~ServerApplication(){
			
		
			delete serverCore ;
			//delete requestManager;
			delete netCore;
			
		}
