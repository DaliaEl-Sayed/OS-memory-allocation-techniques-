#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;
int process;


void first_fit () {

    int num ;
    cout << "enter number of processes = " ;
    cin >> num ;
    cout << endl ;
    int * arr = new int [num] ;
    cout << "enter size of each process" << endl ;
    for (int i = 0 ; i < num ; i++) {
        cout << "process " << i+1 << " = " ;
        cin >>  arr [i] ;

    }

    char exit = 'c' ;
    int input_first_add ;
    int input_hole_size ;
    vector <int> first_address ;
    vector <int> sizee ;
    cout << "enter hole's first address and size " << endl ;
    while (1) {

        cout << "hole's first add = " ;
        cin >> input_first_add ;
        first_address.push_back(input_first_add) ;
        cout << endl ;
        cout << "hole size = " ;
        cin >> input_hole_size ;
        sizee.push_back(input_hole_size) ;
        cout << endl ;
        cout << "to input another hole's first address and size press 'c' or 'C'. " << endl << " if u r done enter 'E' or 'e' : " ;
        cin >> exit ;
        if (exit == 'E' || exit == 'e') {
            break ;
        }
    }

    for (int y = 0 ; y < first_address.size(); y++) {

        for (int z = 0 ; z < first_address.size() ; z++ ) {

            if ((first_address.at(y)+ sizee.at(y)) == first_address.at(z)) {

                int p = sizee.at(y) ; int o = sizee.at(z) ;

                int tt = p + o ;

                sizee.erase(sizee.begin()+z);

                sizee.insert(sizee.begin()+z , 0) ;

                sizee.erase(sizee.begin()+y);

                sizee.insert(sizee.begin()+y ,tt) ;

                first_address.erase(first_address.begin()+ z) ;

                first_address.insert(first_address.begin()+z, 0) ;

            }
        }

    }

    first_address.erase(remove(first_address.begin (), first_address.end() , 0 ), first_address.end()) ;
    sizee.erase(remove(sizee.begin(),sizee.end(),0) , sizee.end()) ;

    for (int i = 0 ; i < first_address.size() ; i ++ ) {

        cout << first_address [i] << " "  ;

    }

    cout << endl ;

    for (int i = 0 ; i < sizee.size() ; i++) {

        cout << sizee [i] << " " ;
    }

    cout << endl ;

    int memory [100][5] = {0}; vector <int> ready_queue ; vector <int> ready_queue_num_of_process ;
    for (int i=0 ; i < first_address.size() ; i++) {

        int x = first_address.at(i);
        memory [x][0] = first_address.at(i) ;
        memory [x][1] = sizee.at(i) ;
    }

    for (int i = 0 ; i < num ; i++) {

        int flag = 0 ;

        for (int j = 0 ; j < 100 ; j++) {

            if (memory[j][4] == 0 && memory[j][1] >= arr [i])  {
                memory [j][2] = arr[i] ;
                memory [j][4] = 1 ;
                memory [j][3] = i+1 ;
                flag = 1 ;
                break ;
            }

        }

        if (flag == 0) {

            int x = arr [i] ;
            ready_queue.push_back(x) ;
            ready_queue_num_of_process.push_back(i+1) ;

        }



    }

    for (int i = 0 ; i < 100 ; i++) {

        if (memory [i][1] != 0){

                cout << "    |---------|  " << memory [i][0] << endl;
                cout << "    |         |  " << endl ;

                cout << "    |    P" << memory[i][3]<< "   |  " << memory [i][1] <<endl   ;
                cout << "    |         |" << endl ;

                cout << "    |   "<< memory[i][2] << "   |  " << endl ;
                cout << "    |         |  " << endl ;
                cout << "    |---------|  " << endl ;
                cout << "    |\\\\\\\\\|  " << endl ;
            }
    }

    cout << "ready queue is " << endl ;
    for (int i = 0 ; i < ready_queue_num_of_process.size() ; i++)
        cout <<"process : " << ready_queue_num_of_process [i] << "\t";

    cout << endl ;

    for (int i = 0 ; i < ready_queue.size() ; i++ )
        cout <<"          "<< ready_queue[i] << "\t" ;

    cout << endl ;


    int flag2 = 0;
    int swapp_out  ;
    int swapp_in  ;
    int swapp_in_value ;
    int flag3 = 0 ;
    int choose ;
    cout << "if u want to swap a process enter 1, if not press 2 : " ;
    cin >> choose ;
    cout << endl ;
    if (choose == 1){
        cout << "choose which process to be swapped out : " ;
        cin >> swapp_out ;
        cout << endl ;
        cout << "choose 1 process number from ready queue to be swapped in : "  ;
        cin >> swapp_in ;
        cout << endl ;

        for (int i = 0 ; i < ready_queue_num_of_process.size() ; i++) {

            if (ready_queue_num_of_process.at (i) == swapp_in) {

                swapp_in_value = ready_queue.at(i) ;
                flag2 = 1 ;
            }
        }



        for (int i = 0 ; i < 100 ; i ++ ) {

            if ( memory [i][3] == swapp_out &&  flag2 == 1) {

                if (memory [i][1] >=  swapp_in_value  ){

                    memory [i][3] = swapp_in ;
                    memory [i][2] = swapp_in_value ;
                    flag3 = 1 ;

                    break ;

                }

                else {
                    cout << "space of hole is not big enough " ;
                    break ; }


            }

        }

        if (flag3 == 1) {

            for (int i = 0 ; i < 100 ; i++) {

                if (memory [i][1] != 0){

                    cout << "    |---------|  " << memory [i][0] << endl;
                    cout << "    |         |  " << endl ;

                    cout << "    |    P" << memory[i][3]<< "   |  " << memory [i][1] <<endl   ;
                    cout << "    |         |" << endl ;

                    cout << "    |   "<< memory[i][2] << "   |  " << endl ;
                    cout << "    |         |  " << endl ;
                    cout << "    |---------|  " << endl ;
                    cout << "    |/////////|  " << endl ;
                }
            }
        }
    }

    int in;
    cout << "to deallocate all the processes press 1, if not press 2 : " ;
    cin >> in;
    if (in == 1) {
        for (int i = 0 ; i < 100 ; i++) {
            if (memory[i][3]!= 0 ){
                memory [i][2]= 0 ;
                memory [i][3] = 0 ;
                memory [i][4] = 0 ;
            }
        }

        for (int i = 0 ; i < 100 ; i++) {

                if (memory [i][1] != 0){

                    cout << "    |----------|  " << memory [i][0] << endl;
                    cout << "    |          |  " << endl ;

                    cout << "    |          |  " << memory [i][1] <<endl   ;
                    cout << "    |   hole   |  " << endl ;

                    cout << "    |          |  " << endl ;
                    cout << "    |          |  " << endl ;
                    cout << "    |----------|  " << endl ;
                    cout << "    |//////////|  " << endl ;
                }
        }

    }
}

void best_fit () {

    int mem[100],processes[100],n1,n2,flags[100],allocation[100];
	int i,j,smallest;
	for(i=0;i < 100;i++)
	{
		flags[i]=0;
		allocation[i]=-1;
	}
	cout<<"\n Enter no.of holes:";
	cin>>n1;
	cout<<"\n Enter size of each hole:" << endl;
	for(i=0;i < n1;i++) {
	    cout << " Hole " << i+1 << " = " ;
		cin>>mem[i];}
	cout<<"\n enter no.of processes:";
	cin>>n2;
	cout<<"\n Enter size of each process:" << endl;
	for(i=0;i < n2;i++) {
	    cout << "process " << i+1 << " = " ;
		cin>>processes[i]; }
	//allocation as per best fit
	for(i=0;i < n2;i++)
	{
		smallest=-1;
		for(j=0;j < n1;j++)
			if(flags[j]==0 && mem[j] >= processes[i])
			{
				smallest=j;
				break;
			}
		for(;j < n1;j++)
			if(flags[j]==0 && mem[j] >= processes[i] && mem[j] < mem[smallest])
				smallest=j;
		if(smallest!=-1)
		{
			allocation[smallest]=i;
			flags[smallest]=1;
		}
	}
	//display allocation details
	cout<<"\nhole     hole_size     process no.    P_size";
	for(i=0;i < n1;i++)
	{
		cout<<"\n"<<i+1<<"      "<<mem[i]<<"     ";
		if(flags[i]==1)
			cout<<allocation[i]<<"    "<<processes[allocation[i]];
		else
			cout<<"-----";
	}

}

void worst_fit () {


    int input ;
    cout << "enter number of process : " ;
    cin >> input ;
    cout << endl ;
    int * arr = new int [input] ;
    cout << "enter size of each process : " << endl ;
    for (int i = 0 ; i < input ; i++) {
        cout << "process " << i+1 << " = " ;
        cin >>  arr [i] ;

    }

    char exit = 'c' ;
    int input_first_add ;
    int input_hole_size ;
    vector <int> first_address ;
    vector <int> sizee ;
    cout << "enter hole's first address and size " << endl ;
    while (1) {

        cout << "hole's first add = " ;
        cin >> input_first_add ;
        first_address.push_back(input_first_add) ;
        cout << endl ;
        cout << "hole size = " ;
        cin >> input_hole_size ;
        sizee.push_back(input_hole_size) ;
        cout << endl ;
        cout << "to input another hole's first address and size press 'c' or 'C'. " << endl << " if u r done enter 'E' or 'e' : " ;
        cin >> exit ;
        if (exit == 'E' || exit == 'e') {
            break ;
        }
    }



     for (int y = 0 ; y < first_address.size(); y++) {

        for (int z = 0 ; z < first_address.size() ; z++ ) {

            if ((first_address.at(y)+ sizee.at(y)) == first_address.at(z)) {

                int p = sizee.at(y) ; int o =  sizee.at(z) ;

                int tt = p + o ;

                sizee.erase(sizee.begin()+z);

                sizee.insert(sizee.begin()+z , 0) ;

                sizee.erase(sizee.begin()+y);

                sizee.insert(sizee.begin()+y ,tt) ;

                first_address.erase(first_address.begin()+ z) ;

                first_address.insert(first_address.begin()+z, 0) ;

            }
        }

    }

    first_address.erase(remove(first_address.begin (), first_address.end() , 0 ), first_address.end()) ;
    sizee.erase(remove(sizee.begin(),sizee.end(),0) , sizee.end()) ;

    int memory [100][6] = {0} ;
    for (int i = 0 ; i < first_address.size() ; i++) {
        int x = first_address.at(i) ;
        memory [x][0] = first_address.at(i) ;
        memory [x][1] = sizee.at(i) - 1;
        memory [x][5] = i+1 ;
        for (int y = 1 ; y<sizee.at(i) ; y++) {
            memory [first_address.at(i)+y][5] = i+1 ;
            memory [first_address.at(i)+y][0] = first_address.at(i)+y ;
            memory [first_address.at(i)+y][1] = sizee.at(i)-1-y ;
        }
    }

    vector <int> ready_queue_value ; vector <int> ready_queue_index ;
    for (int i = 0 ; i < input ; i++){
        int x = 0 ;
        int temp = 0 ;
        int flag = 0 ;
        for (int j = 0 ; j < 100 ; j ++) {

            if (memory[j][1] > temp && memory[j][4] == 0 ){
                temp = memory[j][1]  ;
                x = j ;
            }

        }

        if (temp >= arr[i] ) {

            flag = 1 ;

            for (int k = 0 ; k<arr[i] ; k++) {

                memory[x+k][2] = arr[i];
                memory[x+k][4] = 1 ;
                memory[x+k][3] = i+1 ;

            }
        }

        if (flag == 0) {

            ready_queue_index . push_back (i+1) ;
            ready_queue_value . push_back (arr[i]);
        }



    }




    if (ready_queue_index.size() == 0) {
        cout << "ready queue is empty"<<endl;
    }
    else {

        cout << endl << "ready queue is : " << endl ;
        for (int i = 0 ; i < ready_queue_index.size(); i++) {

            int bb = ready_queue_index .at(i);
            cout <<"P" << bb << " : "  ;
            int qq = ready_queue_value.at(i);
            cout << qq << endl ;
        }
    }

    for (int i = 0 ; i < input ; i++) {

        for (int j = 0 ; j < 100 ; j++) {

            if (memory[j][2] == arr[i]){
                cout << "    |---------| first_address = " << memory [j][0] << endl;
                cout << "    |         |  " << endl ;

                cout << "    |    P" << memory[j][3]<< "   |  " <<endl   ;

                cout << "    |Psize=" << memory [j][2] << "  |" << endl ;

                cout << "    | hole "<< memory[j][5] << " |  " << endl ;
                cout << "    | number  |  " << endl ;
                cout << "    |---------|  " << endl ;

                break ;

            }
        }
    }


    ////////////////////////////////// swap option

    int flag2 = 0;
    int swapp_out  ;
    int swapp_in  ;
    int swapp_in_value ;
    int flag3 = 0 ;
    int choose ;
    cout << "if u want to swap a process enter 1, if not press 2 : " ;
    cin >> choose ;
    cout << endl ;
    if (choose == 1){
        cout << "choose which process to be swapped out : " ;
        cin >> swapp_out ;
        cout << endl ;
        cout << "choose 1 process number from ready queue to be swapped in : "  ;
        cin >> swapp_in ;
        cout << endl ;
        int flag=0 ;
        for (int i = 0 ; i < ready_queue_index.size() ; i++) {

            if (ready_queue_index.at (i) == swapp_in) {

                swapp_in_value = ready_queue_value.at(i) ;
                flag2 = 1 ;
                flag = 1;
            }
            else {

                flag = 0;
            }
        }

        if (flag == 0) {

            cout << "invalid input : the process is not at ready queue " << endl ;
        }


        for (int i = 0 ; i < 100 ; i ++ ) {

            if ( memory [i][3] == swapp_out &&  flag2 == 1) {

                if (memory [i][1]+1 >=  swapp_in_value  ){

                    for (int j = 0 ; j < swapp_in_value ; j++) {

                        memory [i+j][3] = swapp_in;
                        memory [i+j][2] = swapp_in_value ;
                        flag3 = 1 ;

                    }



                    break ;

                }

                else {
                    cout << "space of hole is not big enough " ;
                    break ; }
            }
        }

        if (flag3==1) {


            for (int i = 0 ; i < input ; i++) {

                for (int j = 0 ; j < 100 ; j++) {

                    if (memory[j][2] == arr[i]){
                        cout << "    |---------| first_address = " << memory [j][0] << endl;
                        cout << "    |         |  " << endl ;

                        cout << "    |    P" << memory[j][3]<< "   |  " <<endl   ;

                        cout << "    |Psize=" << memory [j][2] << " |" << endl ;

                        cout << "    | hole "<< memory[j][5] << "  |  " << endl ;
                        cout << "    | number  |  " << endl ;
                        cout << "    |---------|  " << endl ;

                        break ;

                    }
                }
            }
        }

    }


}
int main()
{

    cout << "for first fit algorithm enter 1" <<endl << "for best fit algorithm enter 2 " << endl << "for worst fit algorithm enter 3" << endl ;
    cout << "your choice is : " ;
    cin >> process ;

    if (process == 1) {

        first_fit() ;

    }
    else if (process == 2) {

        best_fit() ;

    }

    else if (process == 3) {

        worst_fit();
    }
    else {
        cout << "error try again" << endl ;
    }
    system ("pause") ;
    return 0;
}
