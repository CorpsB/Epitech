import jenkins.model.*
import javaposse.jobdsl.plugin.ExecuteDslScripts

def instance = Jenkins.instance
def jobDslScript = new File(instance.root, "dsl-scripts/job_dsl.groovy")

if (jobDslScript.exists()) {
    def scriptText = jobDslScript.text
    def executeDsl = new ExecuteDslScripts()
    executeDsl.setScriptText(scriptText)
    executeDsl.run()
    println("✅ Job DSL chargé automatiquement au démarrage.")
} else {
    println("❌ Fichier job_dsl.groovy introuvable. Assurez-vous qu'il est bien dans dsl-scripts/")
}
