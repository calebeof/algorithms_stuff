vector<vector<pair<int, int> > > graph; //(vertex) -> (adj, distance)
const int INF = int(1e9);

int Dijkstra (int origin, int destiny)
{
	vector<int>dist(graph.size(), INF); 
	dist[origin] = 0; 
	set<pair<int, int> > s; 
	s.insert(make_pair(0, origin));
	
	while(!s.empty())
	{
		pair<int, int> f = *s.begin();
		int distance = f.first, vertex = f.second; 
		s.erase(s.begin()); 

		for (int i=0; i<graph[vertex].size(); i++) 
		{
			int adj = graph[vertex][i].first;
			int dist_adj = graph[vertex][i].second;
			if (dist[adj] > distance + dist_adj) 
			{
				dist[adj] = distance + dist_adj; 
				s.insert(make_pair(dist[adj], adj)); 
			}
		}
	}
	
	return dist[destiny]; 
}
