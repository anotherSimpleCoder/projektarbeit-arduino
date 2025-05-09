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
                dir('documents') {
                    sh 'Rscript -e \'rmarkdown::render(\"*.Rmd\")\''
                    archiveArtifacts artifacts: '*.pdf', fingerprint: true
                }
            }
        }
    }
}