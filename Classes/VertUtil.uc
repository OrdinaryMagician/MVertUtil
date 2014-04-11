//
//	VertUtil.uc : Class providing Vertex/Mesh utility functions.
//	(C)2013 Marisa Kirisame, UnSX Team.
//
class VertUtil extends Object native;
// native functions
native static final function vector GetVertexLocation( Mesh Mesh, Actor Actor,
	int Index );
native static final function vector GetVertexLocationLOD( LodMesh LodMesh,
	Actor Actor, int Index );
native static final function int GetVertexCount( Mesh Mesh );
native static final function vector GetMeshSize( Mesh Mesh );
native static final function SetMeshSize( Mesh Mesh, vector NewSize );
native static final function vector GetMeshOrigin( Mesh Mesh );
native static final function SetMeshOrigin( Mesh Mesh, vector NewOrigin );
native static final function rotator GetMeshRotation( Mesh Mesh );
native static final function SetMeshRotation( Mesh Mesh, rotator NewRotation );
// non-native functions
static final function int GetClosestVertex( Mesh Mesh, Actor Actor,
	Vector Test )
{
	local vector Prev, End;
	local float Dist;
	local int Index, Count, i;
	Prev = vect(6556,65536,65536);
	Dist = 65536;
	Index = -1;
	Count = GetVertexCount(Mesh);
	for ( i=0; i<Count; i++ )
	{
		if ( Mesh.IsA('LODMesh') )
			End = GetVertexLocationLOD(LODMesh(Mesh),Actor,i);
		else
			End = GetVertexLocation(Mesh,Actor,i);
		if ( VSize(Test-End) < Dist )
			Index = i;
		Dist = VSize(Test-End);
		Prev = End;
	}
	return Index;
}
