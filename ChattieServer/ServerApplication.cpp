#include "ServerApplication.h"

		ServerApplication::ServerApplication(){
			
			serverCore = new ServerCore();
			netCore = new NetCore(serverCore);
							
					
		}
		
		void ServerApplication::run(){
		
				
		}
		

		
		ServerApplication::~ServerApplication(){
			
		
			delete serverCore ;
			delete netCore;
			
		}
