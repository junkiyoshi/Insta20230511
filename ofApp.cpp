#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(255);
	ofSetLineWidth(0.5);

	auto ico_sphere = ofIcoSpherePrimitive(300, 2);
	this->base_mesh = ico_sphere.getMesh();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);
	
	ofSetColor(0);
	for (auto v : this->base_mesh.getVertices()) {

		for (int i = 0; i < 40; i++) {

			auto rotation_x = glm::rotate(glm::mat4(), ofMap(ofNoise(glm::vec4(v * 0.00035, ofGetFrameNum() * 0.008 + i * 0.00065)), 0, 1, -360, 360) * (float)DEG_TO_RAD, glm::vec3(1, 0, 0));
			auto rotation_y = glm::rotate(glm::mat4(), ofMap(ofNoise(glm::vec4(v * 0.00035, ofGetFrameNum() * 0.008 + i * 0.00065)), 0, 1, -360, 360) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
			auto rotation_z = glm::rotate(glm::mat4(), ofMap(ofNoise(glm::vec4(v * 0.00035, ofGetFrameNum() * 0.008 + i * 0.00065)), 0, 1, -360, 360) * (float)DEG_TO_RAD, glm::vec3(0, 0, 1));
			glm::vec3 vertex = glm::vec4(v, 0) * rotation_z * rotation_y * rotation_x;
			vertex.z = 0;

			ofDrawCircle(vertex, 8);
		}
	}

	ofSetColor(255);
	for (auto v : this->base_mesh.getVertices()) {

		for (int i = 0; i < 40; i++) {

			auto rotation_x = glm::rotate(glm::mat4(), ofMap(ofNoise(glm::vec4(v * 0.00035, ofGetFrameNum() * 0.008 + i * 0.00065)), 0, 1, -360, 360) * (float)DEG_TO_RAD, glm::vec3(1, 0, 0));
			auto rotation_y = glm::rotate(glm::mat4(), ofMap(ofNoise(glm::vec4(v * 0.00035, ofGetFrameNum() * 0.008 + i * 0.00065)), 0, 1, -360, 360) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
			auto rotation_z = glm::rotate(glm::mat4(), ofMap(ofNoise(glm::vec4(v * 0.00035, ofGetFrameNum() * 0.008 + i * 0.00065)), 0, 1, -360, 360) * (float)DEG_TO_RAD, glm::vec3(0, 0, 1));
			glm::vec3 vertex = glm::vec4(v, 0) * rotation_z * rotation_y * rotation_x;
			vertex.z = 0;

			ofDrawCircle(vertex, 5);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}