varying vec4 uv;
uniform sampler2D texture;
uniform float lifeTimeOpacity;
uniform vec3 colorModifier;
uniform float state_x;
uniform float state_y;

void main() {
    vec2 uvtexture=uv.st;
    uvtexture.x += state_x;
    uvtexture.y += state_y;
    gl_FragColor = texture2D(texture, uvtexture/4.0f);
    gl_FragColor.rgb *=colorModifier;
    gl_FragColor.a *=lifeTimeOpacity;
}
