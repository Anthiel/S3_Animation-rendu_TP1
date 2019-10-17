varying vec4 uv;
uniform sampler2D texture;
uniform float lifeTimeOpacity;
uniform vec3 colorModifier;
uniform float state;

void main() {
    vec2 uvtexture=uv.st;
    //uvtexture.x = uvtexture.x+state%4;
    //uvtexture.y = uvtexture.y+state/4;
    uvtexture /=4.0f;
    gl_FragColor = texture2D(texture, uvtexture);
    gl_FragColor.rgb *=colorModifier;
    gl_FragColor.a *=lifeTimeOpacity;
}
