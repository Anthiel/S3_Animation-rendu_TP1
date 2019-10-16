varying vec4 uv;
uniform sampler2D texture;
uniform float lifeTimeOpacity;
uniform vec3 colorModifier;

void main() {
      gl_FragColor = texture2D(texture, uv.st);
      gl_FragColor.rgb *=colorModifier;
      gl_FragColor.a *=lifeTimeOpacity;
}
