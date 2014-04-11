/*
	VertUtil.cpp : Minimal Vertex/Mesh utility functions.
	"And just when I thought C++ couldn't get any worse,
	 here I am doing Unreal Engine native code!"
	(C)2013 Marisa Kirisame, UnSX Team.
*/
#include "../Inc/MVertUtil.h"
/* 'tis our current package */
IMPLEMENT_PACKAGE(MVertUtil);
/* The class for this thingio */
IMPLEMENT_CLASS(UVertUtil);
/* Get the location of a vertex in a non-LOD mesh */
IMPLEMENT_FUNCTION(UVertUtil,-1,execGetVertexLocation);
void UVertUtil::execGetVertexLocation( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execGetVertexLocation);
	P_GET_OBJECT(UMesh,Mesh);
	P_GET_ACTOR(Actor);
	P_GET_INT(Index);
	P_FINISH;
	TArray<FVector> Verts(Mesh->FrameVerts);
	Mesh->GetFrame(&Verts(0),sizeof(FVector),GMath.UnitCoords,Actor);
	*(FVector*)Result = Verts(Index);
	unguard;
}
/* Get the location of a vertex in a LOD mesh */
IMPLEMENT_FUNCTION(UVertUtil,-1,execGetVertexLocationLOD);
void UVertUtil::execGetVertexLocationLOD( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execGetVertexLocationLOD);
	P_GET_OBJECT(ULodMesh,LodMesh);
	P_GET_ACTOR(Actor);
	P_GET_INT(Index);
	P_FINISH;
	int LOD = LodMesh->FrameVerts;
	TArray<FVector> Verts(LOD);
	LodMesh->GetFrame(&Verts(0),sizeof(FVector),GMath.UnitCoords,Actor,
		LOD);
	*(FVector*)Result = Verts(Index);
	unguard;
}
/* Get the total number of vertices in a mesh */
IMPLEMENT_FUNCTION(UVertUtil,-1,execGetVertexCount);
void UVertUtil::execGetVertexCount( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execGetVertexCount);
	P_GET_OBJECT(UMesh,Mesh);
	P_FINISH;
	*(INT*)Result = Mesh->FrameVerts;
	unguard;
}
/* Get the scale of a mesh */
IMPLEMENT_FUNCTION(UVertUtil,-1,execGetMeshSize);
void UVertUtil::execGetMeshSize( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execGetMeshSize);
	P_GET_OBJECT(UMesh,Mesh);
	P_FINISH;
	*(FVector*)Result = Mesh->Scale;
	unguard;
}
/* Set the scale of a mesh */
IMPLEMENT_FUNCTION(UVertUtil,-1,execSetMeshSize);
void UVertUtil::execSetMeshSize( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execSetMeshSize);
	P_GET_OBJECT(UMesh,Mesh);
	P_GET_VECTOR(NewSize);
	P_FINISH;
	Mesh->Scale = NewSize;
	unguard;
}
/* Get mesh origin vector */
IMPLEMENT_FUNCTION(UVertUtil,-1,execGetMeshOrigin);
void UVertUtil::execGetMeshOrigin( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execGetMeshOrigin);
	P_GET_OBJECT(UMesh,Mesh);
	P_FINISH;
	*(FVector*)Result = Mesh->Origin;
	unguard;
}
/* Set mesh origin vector */
IMPLEMENT_FUNCTION(UVertUtil,-1,execSetMeshOrigin);
void UVertUtil::execSetMeshOrigin( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execSetMeshOrigin);
	P_GET_OBJECT(UMesh,Mesh);
	P_GET_VECTOR(NewOrigin);
	P_FINISH;
	Mesh->Origin = NewOrigin;
	unguard;
}
/* Get mesh origin rotator */
IMPLEMENT_FUNCTION(UVertUtil,-1,execGetMeshRotation);
void UVertUtil::execGetMeshRotation( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execGetMeshRotation);
	P_GET_OBJECT(UMesh,Mesh);
	P_FINISH;
	*(FRotator*)Result = Mesh->RotOrigin;
	unguard;
}
/* Set mesh origin rotator */
IMPLEMENT_FUNCTION(UVertUtil,-1,execSetMeshRotation);
void UVertUtil::execSetMeshRotation( FFrame& Stack, RESULT_DECL )
{
	guard(UVertUtil::execSetMeshRotation);
	P_GET_OBJECT(UMesh,Mesh);
	P_GET_ROTATOR(NewRotation);
	P_FINISH;
	Mesh->RotOrigin = NewRotation;
	unguard;
}
