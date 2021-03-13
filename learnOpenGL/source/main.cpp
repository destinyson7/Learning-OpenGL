#include <glad/glad.h>
#include <GLFW/glfw3.h>
// #include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// #include <learnopengl/filesystem.h>
#include <shaders/shader_s.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("./../source/shaders/3.3.shader.vs", "./../source/shaders/3.3.shader.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    float vertices[] = {
        0.0f, 0.0f, 0.5f, 0.647244066f, 0.8206990548f, 0.7488152685f,
        -0.3f, -0.3f, 0.0f, 0.647244066f, 0.8206990548f, 0.7488152685f,
        -0.0901838146f, -0.4145683051f, 0.0f, 0.647244066f, 0.8206990548f, 0.7488152685f,
        0.0f, 0.0f, 0.5f, 0.233113241f, 0.8213544667f, 0.8384927377f,
        -0.0901838146f, -0.4145683051f, 0.0f, 0.233113241f, 0.8213544667f, 0.8384927377f,
        0.1482650947f, -0.3975141025f, 0.0f, 0.233113241f, 0.8213544667f, 0.8384927377f,
        0.0f, 0.0f, 0.5f, 0.8822849974f, 0.2775745009f, 0.3165494291f,
        0.1482650947f, -0.3975141025f, 0.0f, 0.8822849974f, 0.2775745009f, 0.3165494291f,
        0.339640884f, -0.2542519811f, 0.0f, 0.8822849974f, 0.2775745009f, 0.3165494291f,
        0.0f, 0.0f, 0.5f, 0.7375305647f, 0.4419038377f, 0.5358605815f,
        0.339640884f, -0.2542519811f, 0.0f, 0.7375305647f, 0.4419038377f, 0.5358605815f,
        0.4231830925f, -0.0302666521f, 0.0f, 0.7375305647f, 0.4419038377f, 0.5358605815f,
        0.0f, 0.0f, 0.5f, 0.2680442634f, 0.2234442467f, 0.2938449037f,
        0.4231830925f, -0.0302666521f, 0.0f, 0.2680442634f, 0.2234442467f, 0.2938449037f,
        0.3723676591f, 0.203328125f, 0.0f, 0.2680442634f, 0.2234442467f, 0.2938449037f,
        0.0f, 0.0f, 0.5f, 0.0340361008f, 0.1706504285f, 0.7884577258f,
        0.3723676591f, 0.203328125f, 0.0f, 0.0340361008f, 0.1706504285f, 0.7884577258f,
        0.203328125f, 0.3723676591f, 0.0f, 0.0340361008f, 0.1706504285f, 0.7884577258f,
        0.0f, 0.0f, 0.5f, 0.1048857897f, 0.055636617f, 0.3964869888f,
        0.203328125f, 0.3723676591f, 0.0f, 0.1048857897f, 0.055636617f, 0.3964869888f,
        -0.0302666521f, 0.4231830925f, 0.0f, 0.1048857897f, 0.055636617f, 0.3964869888f,
        0.0f, 0.0f, 0.5f, 0.4295926491f, 0.4858345552f, 0.9137123145f,
        -0.0302666521f, 0.4231830925f, 0.0f, 0.4295926491f, 0.4858345552f, 0.9137123145f,
        -0.2542519811f, 0.339640884f, 0.0f, 0.4295926491f, 0.4858345552f, 0.9137123145f,
        0.0f, 0.0f, 0.5f, 0.5566548495f, 0.6336180953f, 0.4166151827f,
        -0.2542519811f, 0.339640884f, 0.0f, 0.5566548495f, 0.6336180953f, 0.4166151827f,
        -0.3975141025f, 0.1482650947f, 0.0f, 0.5566548495f, 0.6336180953f, 0.4166151827f,
        0.0f, 0.0f, 0.5f, 0.425511578f, 0.8655573176f, 0.4756455043f,
        -0.3975141025f, 0.1482650947f, 0.0f, 0.425511578f, 0.8655573176f, 0.4756455043f,
        -0.4145683051f, -0.0901838146f, 0.0f, 0.425511578f, 0.8655573176f, 0.4756455043f,
        0.0f, 0.0f, 0.5f, 0.4118820944f, 0.1537809429f, 0.2824519927f,
        -0.4145683051f, -0.0901838146f, 0.0f, 0.4118820944f, 0.1537809429f, 0.2824519927f,
        -0.3f, -0.3f, 0.0f, 0.4118820944f, 0.1537809429f, 0.2824519927f

    };
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // load and create a texture
    // -------------------------
    // unsigned int texture1, texture2;
    // texture 1
    // ---------
    // glGenTextures(1, &texture1);
    // glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    // int width, height, nrChannels;
    // stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // unsigned char *data = stbi_load(FileSystem::getPath("resources/textures/container.jpg").c_str(), &width, &height, &nrChannels, 0);
    // if (data)
    // {
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // {
    //     std::cout << "Failed to load texture" << std::endl;
    // }
    // stbi_image_free(data);
    // texture 2
    // ---------
    // glGenTextures(1, &texture2);
    // glBindTexture(GL_TEXTURE_2D, texture2);
    // // set the texture wrapping parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // // set texture filtering parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // // load image, create texture and generate mipmaps
    // data = stbi_load(FileSystem::getPath("resources/textures/awesomeface.png").c_str(), &width, &height, &nrChannels, 0);
    // if (data)
    // {
    //     // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // {
    //     std::cout << "Failed to load texture" << std::endl;
    // }
    // stbi_image_free(data);

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    // ourShader.use();
    // ourShader.setInt("texture1", 0);
    // ourShader.setInt("texture2", 1);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // bind textures on corresponding texture units
        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, texture1);
        // glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, texture2);

        // activate shader
        ourShader.use();

        // create transformations
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        // retrieve the matrix uniform locations
        unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
        unsigned int viewLoc = glGetUniformLocation(ourShader.ID, "view");
        // pass them to the shaders (3 different ways)
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        ourShader.setMat4("projection", projection);

        // render box
        glBindVertexArray(VAO);
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, 33);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
