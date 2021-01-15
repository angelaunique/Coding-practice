
//两层数据结构，外层为hashmap，内层为list pairs
// map -- 确认key是否存在 o(1)
//list: 用来插入在最前面 o(1) 和移动到最后面 o(1)
class LRUCache {
private:    
    int capacity_; 
    list<pair<int,int>> cache_; //inner structure to hold key-value pairs
    unordered_map< int, list<pair<int,int>> :: iterator> m_; // iterator for map:<  key, < key, value>>  
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    // get will move the recent use one to the Front 
    int get(int key) {
        const auto it = m_.find(key); // find corresponding key in MAP 
        // if key does not exist
        if( it == m_.cend()) return -1; // if iterate until end of map not found
        // otherwise we found the key, move this key to the fround of the list
        cache_.splice(cache_.begin(),cache_,it->second); // it->second == list< pair<int,int> struct in MAP
        // cache_.begin(): position ;cache_: list. ;it->second: value
        return it ->second ->second; // it ->second| second iterator, it ->second ->second; value in the second iterator
    }
    
    // put will move the recent use one to the front
    // can use list or vector to remove the last one, bc recently used ones was moved to the front, 
    //but since requre time complexity is O(1), vector needs O(n) to remove element, thus can only use list( double linked list)
    
    void put(int key, int value) {
        const auto it = m_.find(key);
        // key already exists
        if( it != m_.cend()){
            // Update the value
            it-> second -> second = value;
            //move this key to the front of the list
            cache_.splice(cache_.begin(),cache_,it->second);
            return;  
        }
       
    // Key doesn not exist  
    //Reached the capacity, remove the oldest element
    if (cache_.size() == capacity_) {
            const auto& node = cache_.back();
            m_.erase(node.first);// map erase
            cache_.pop_back();// list pop back
        }
    
    // Insert the entry into the FRONT of linklist and update mapping
    cache_.emplace_front ( key, value);//emplace_front will create a new node
    m_[key] = cache_.begin(); //cache_.begin() is the first pari in the list
    }
   /* emplace:   To put into place or position，放置，安放
   The vector::emplace() is an STL in C++ which extends container by inserting new element at position. Reallocation happens only if there is a need of more space. Here the container size increases by one*/
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
Transfers elements from x into the container, inserting them at position.
void splice (const_iterator position, list& x);
void splice (const_iterator position, list&& x);
single element (2)	
void splice (const_iterator position, list& x, const_iterator i);
void splice (const_iterator position, list&& x, const_iterator i);
element range (3)	
void splice (const_iterator position, list& x,
             const_iterator first, const_iterator last);
void splice (const_iterator position, list&& x,
             const_iterator first, const_iterator last);
             
Transfers elements from x into the container, inserting them at position. */       


/*

int main ()
{
  std::list<int> mylist1, mylist2;
  std::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=4; ++i)
     mylist1.push_back(i);      // mylist1: 1 2 3 4

  for (int i=1; i<=3; ++i)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2

  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
                                          
  mylist2.splice (mylist2.begin(),mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.
  it = mylist1.begin();
  std::advance(it,3);           // "it" points now to 30

  mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20

  std::cout << "mylist1 contains:";
  for (it=mylist1.begin(); it!=mylist1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "mylist2 contains:";
  for (it=mylist2.begin(); it!=mylist2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}*/











