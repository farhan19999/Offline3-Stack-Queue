#include "Queue.cpp"

int main()
{
    Queue<char>q;
    string string_old,string_new;
    vector<int>counter(26);
    cin>>string_old;
    char cur;

    for(int i = 0 ; i<string_old.size() ; ++i)
    {
        counter[string_old[i]-'a']++;

        //when found a non repeating character enqueued to the queue
        if(counter[string_old[i]-'a'] == 1) q.enqueue(string_old[i]);


        if(i==0)
        {
            cur = q.front();
            q.dequeue();
        }


        if(cur == '#' && q.isEmpty())string_new.push_back(cur);

        else if(counter[cur-'a'] == 1 && cur != '#') string_new.push_back(cur);

        else
        {
            //finding next non-repeating character in the queue
            while(counter[cur-'a'] != 1 && !q.isEmpty())
            {
                cur = q.front();
                q.dequeue();
            }

            if(counter[cur-'a'] != 1 && q.isEmpty())cur = '#';

            string_new.push_back(cur);
        }

    }

    cout<<string_new<<endl;

    return 0;
}
