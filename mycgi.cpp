#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector <string> get_params (string message);
map <string, string> get_key_values(vector <string> params);

int main()
{
	cout << "Content-type: text/html\n\n";
	cout <<"<head>" << endl;
	cout <<"<title>CPP CGI</title>"<<endl;
	cout <<"<meta charset='UTF-8'>"<< endl;
	cout <<"<head>" << endl;
	
  	cout << "<h1>Hello world apo Θοδωρή</h1>";
	string cppstring;
	char *data_l = getenv("CONTENT_LENGTH");
	if (data_l)
	{
		int data_le = stoi(data_l);
		char *data = new char [data_le];
		cin >> data;
		cppstring =data;
		delete []data;
		cout << "<p>DATA : "<<cppstring  <<" :are comming from POST</p>";
	}
	else
	{
		char* myString = getenv("QUERY_STRING");
		cppstring= myString;
		delete myString;
		cout << "<p>DATA : " << cppstring << " :are comming from get</p>";

	}
	
	map <string,string> params = get_key_values(get_params (cppstring));
  	
	cout << "<p>Form input name with value all strings are </p>" << endl;  
    	
	for (auto& x:params) 
    	{
    		cout << "<p>"<<x.first << " : " << x.second << "<p><br/>";
    	}
	//link to return to page with the form 
	cout << "<a href = '../chat/chat_pcgi.php'> return </a>" << endl;
	return 0;
}

vector <string> get_params (string message)
{
	vector <string> params {};
    	while  (message.find('&')!=string::npos)
    	{
        	params.push_back (message.substr(0, message.find('&')));
        	message = message.substr( message.find('&')+1);
    	}
    	params.push_back( message);
    	return params;
}

map <string, string> get_key_values(vector<string> params)
{       
    	map<string,string> mymap = {};
    	for (auto message : params)
    	{
        	mymap.insert( pair <string,string>(message.substr(0, message.find('=')) , message.substr( message.find('=')+1)));
    	}
   	return mymap;
}

