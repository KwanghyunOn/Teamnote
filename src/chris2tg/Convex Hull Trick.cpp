struct cht{
	map<int,int> mp;
	double cross(pi a, pi b){
		return 1.0 * (b.second - a.second) / (a.first - b.first);
	}
	void add(int x, int y){
		if(mp.find(x) != mp.end()){
			if(mp[x] >= y) return;
			mp.erase(x);
		}
		auto it = mp.lower_bound(x);
		if(it != mp.end()){
			auto it2 = ++mp.lower_bound(x);
			while(it2 != mp.end()){
				if(cross(pi(x, y), *it) > cross(*it, *it2)){
					mp.erase(it);
					it = it2;
					it2++;
				}
				else break;
			}
		}
		it = mp.lower_bound(x);
		if(it != mp.begin()){
			it--;
			auto it2 = it;
			if(it2 != mp.begin()){
				it2--;
				while(1){
					if(cross(*it2, *it) > cross(*it, pi(x, y))){
						mp.erase(it);
						it = it2;
						if(it2 == mp.begin()) break;
						else it2--;
					}
					else break;
				}
			}
		}
		mp[x] = y;
	}
	double query(double t){
		if(mp.empty()) return -1e9;
		auto it = --mp.end();
		while(it != mp.begin()){
			auto nxt = it;
			nxt--;
			if(cross(*nxt, *it) > t){
				mp.erase(it);
				it = nxt;
			}
			else break;
		}
		it = --mp.end();
		return it->first * t + it->second;
	}
	double query2(double t){
		if(mp.empty()) return -1e9;
		auto it = mp.begin();
		auto it2 = ++mp.begin();
		while(it2 != mp.end()){
			if(cross(*it, *it2) < t){
				mp.erase(it);
				it = it2;
				it2++;
			}
			else break;
		}
		return it->first * t + it->second;
	}
	void clear(){
		mp.clear();
	}
};
