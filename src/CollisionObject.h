/*
* CinderBullet originally created by Peter Holzkorn on 2/16/10
* 
* Copyright (c) 2012, Ban the Rewind
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or 
* without modification, are permitted provided that the following 
* conditions are met:
* 
* Redistributions of source code must retain the above copyright 
* notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright 
* notice, this list of conditions and the following disclaimer in 
* the documentation and/or other materials provided with the 
* distribution.
* 
* Neither the name of the Ban the Rewind nor the names of its 
* contributors may be used to endorse or promote products 
* derived from this software without specific prior written 
* permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
* COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
*/

#pragma once

// Includes
#include "BulletUtils.h"

namespace bullet
{

	class DynamicsWorld;
	class RigidObject;
	class SoftObject;
	
	class CollisionObjectBase
	{

	public:

		~CollisionObjectBase();

		void							update( double step );

		double							getAge();
		double							getAge() const;
		btCollisionObject*				getBulletBody();
		btCollisionObject*				getBulletBody() const;
		double							getLifespan();
		double							getLifespan() const;
		ci::Matrix44f					getMatrix();
		ci::Matrix44f					getMatrix() const;
		ci::Vec3f&						getPosition();
		const ci::Vec3f&				getPosition() const;
		ci::Quatf&						getRotation();
		const ci::Quatf&				getRotation() const;
		ci::gl::VboMesh&				getVboMesh();
		const ci::gl::VboMesh&			getVboMesh() const;

	protected:

		CollisionObjectBase( btDynamicsWorld* world, const ci::Vec3f &position = ci::Vec3f::zero(), const ci::Quatf &rotation = ci::Quatf() );

		double							mAge;
		btRigidBody						*mRigidBody;
		btSoftBody						*mSoftBody;
		ci::Vec3f						mPosition;
		ci::Quatf						mRotation;
		btDynamicsWorld					*mWorld;

		void							clearVboData();
		void							setVboData( GLenum primitiveType = GL_TRIANGLES );
		std::vector<uint32_t>			mVboIndices;
		ci::gl::VboMesh::Layout			mVboLayout;
		ci::gl::VboMesh					mVboMesh;
		std::vector<ci::Vec3f>			mVboNormals;
		std::vector<ci::Vec3f>			mVboPositions;

		friend class					DynamicsWorld;

	};

}
