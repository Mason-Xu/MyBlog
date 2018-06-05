// Dijkstra算法比较
void Dijkstra(Vertex s){
    while(1){
        V = 未收录顶点中dist最小者;
        if(这样的V不存在){
            break;
        }
        collected[V] = true;
        for(collected[W] == false){
            if(dist[V] + E<v,w> < dist[W]){
                dist[W] = dist[V] + E<v,w>;
                path[W] = V;
            }
        }
    }
}


// Prim算法
void Prim(){
    MST = {S}; // 最小生成树的建立
    while(1){
        V = 未收录顶点中dist最小者;
        if(这样的V不存在){
            break;
        }
        将v收录进MST;
        for(V的每个邻接点W){
            if(W未被收录){
                if(E<v,w> < dist[W]){
                    dist[W] = E<v,w>;
                    parent[W] = V;
                }
            }
        }
    }
}


// Kruskal算法 
void Kruskal(Graph G){
    MST = {};
    while(MST 中不到|V| - 1 条边 && E中还有边){
        从E中取一条权重最小的边E<v,w>;  // 最小堆
        将E<v,w>从E中删除;
        if(E<v,w> 不在MST中构成回路){   // 并查集
            将E<v,w>加入MST;
        }else{
            彻底无视E<v,w>;
        }
    }
}