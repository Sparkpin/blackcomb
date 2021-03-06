#ifndef BLACKCOMB_FREEMOVECAMERA_H
#define BLACKCOMB_FREEMOVECAMERA_H

#include "Camera.h"
#include "../input/MouseWatcher.h"

namespace blackcomb::entity {
/**
 * A camera that can be used to look around a scene freely.
 */
    class FreeMoveCamera : public Camera {
    public:
        void loadViewMatrix(renderer::Shader& shader) override;
        void processInput(base::Window& window, float deltaTime);
        float speed = 5.0f; ///< The speed at which the camera moves.
    private:
        glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    };
}

#endif //BLACKCOMB_FREEMOVECAMERA_H
