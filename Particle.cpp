#include "Particle.hpp"

//初期設定
void Particle::setup(ofVec2f _position, ofVec2f _velocity){
     position = _position;
     velocity = _velocity;
}

//力をリセット
void Particle::resetForce(){
     force.set(0,0);
}

//力を加える
void Particle::addForce(ofVec2f _force){
     force = _force;
}

//力の更新
void Particle::updateForce(){
     force -= velocity * friction;
}

//位置を更新
void Particle::updatePos(){
     velocity += force;
     position += velocity;
}

//画面からはみ出たらバウンドさせる
void Particle::checkBounds(float xmin, float ymin, float xmax, float ymax){
     //画面の端でバウンドする
     if (position.x < xmin || position.x > xmax) {
          velocity.x *= -1;
     }
     if (position.y < ymin || position.y > ymax) {
          velocity.y *= -1;
     }

     //枠内に収める
     if (position.x < xmin) {
          position.x = xmin + (xmin - position.x);
     }
     if (position.x > xmax) {
          position.x = xmax - (position.x - xmax);
     }
     if (position.y < ymin) {
          position.y = ymin + (ymin - position.y);
     }
     if (position.y > ymax) {
          position.y = ymax - (position.y - ymax);
     }
}
//画面からはみ出したら逆側から出てくる
void Particle::checkScreen(float xmin, float ymin, float xmax, float ymax){
     //画面の端でバウンドする
     if (position.x < xmin) {
          position.x = xmax;
     }
     if (position.x > xmax) {
          position.x = xmin;
     }

     //枠内に収める
     if (position.y < ymin) {
          position.y = ymax;
     }
     if (position.y > ymax) {
          position.y = ymin;
     }
}

//描画
void Particle::draw(){
     //透明度を使用可能にする
     ofEnableAlphaBlending();
     //混色を加算混合にする
     glBlendFunc(GL_ONE, GL_ONE);
     //HSBで色を指定する
     ofColor c;
     c.setHsb(ofRandom(255),255,255, 40);
     //色を指定する
     ofSetColor(c);
     ofCircle(position, radius);
}
