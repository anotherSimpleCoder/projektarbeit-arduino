pipeline {
    agent {
        docker {
            image 'rocker/r-rmd'
            args '-u root' 
        }
    }

    stages {
        stage('Build PDF') {
            steps {
                dir('phase1') {
                    sh 'Rscript -e \'rmarkdown::render(\"Phase 1 Entwicklungsumgebung und Build Prozess.Rmd\")\''
                    archiveArtifacts artifacts: '*.pdf', fingerprint: true
                }
            }
        }
    }
}