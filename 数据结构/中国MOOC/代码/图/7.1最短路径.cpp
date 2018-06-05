// dist[W] = S到W的最短距离 S源点
// dist[S] = 0 
// path[W] = S到W的路上经过的某顶点 
void Unweighted(Vertex S){
    Enqueue(S,Q);
    while(!IsEmpty(Q)){
        V = Dequeue(Q);
        for(V的每个邻接点W){
            if(dist[W] == -1){  // 表示没有被访问过
                dist[W] = dist[V] + 1;  // 前一个顶点的距离+1
                path[W] = V;    // 必经过的顶点
                Enqueue(W,Q);     
            }
        }
    }
}


// 有权图的单源最短路径
// Dijkstra算法
void Dijkstra(Vertex s){
    while(1){
        V = 未收录顶点中dist最小者
        if(这样的V不存在){
            break;
        }

        collected[V] = true;
        for(V的每个邻接点W){
            if(collected[W] = false){
                if(dist[V]+E<sub><v,w></sub><dist[W]){
                    dist[W] = dist[V]+E<sub><v,w></sub>;
                    path[W] = V;
                }
            }
        }
    }
}
// 不能存在有负边

// 多源最短路径算法
void Floyd(){ 
    for ( i = 0; i < N; i++ )
        for( j = 0; j < N; j++ ) {
            D[i][j] = G[i][j];
            path[i][j] = -1;
        }
    for( k = 0; k < N; k++ )
        for( i = 0; i < N; i++ )
            for( j = 0; j < N; j++ )
                if( D[i][k] + D[k][j] < D[i][j] ) {
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = k;
                }
}
